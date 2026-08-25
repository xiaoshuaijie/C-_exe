#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define kBufferSize 4096

/* 检查两个路径是否指向同一个已有文件，避免目标文件打开时截断源文件。 */
static int same_file(const char *src_path, const char *dst_path)
{
    struct stat src_info;
    struct stat dst_info;

    if (strcmp(src_path, dst_path) == 0) {
        return 1;
    }

    if (stat(src_path, &src_info) == 0 && stat(dst_path, &dst_info) == 0) {
        return src_info.st_dev == dst_info.st_dev &&
               src_info.st_ino == dst_info.st_ino;
    }

    return 0;
}

/// @brief 复制文件
/// @param src_path 源文件路径
/// @param dst_path 目标文件路径
/// @return 成功返回 0，失败返回 -1
int copy_file(const char *src_path, const char *dst_path)
{
    FILE *src = NULL;                /* 源文件指针，初始化为 NULL */
    FILE *dst = NULL;                /* 目标文件指针，初始化为 NULL */
    unsigned char buffer[kBufferSize]; /* 用于读写数据的缓冲区 */
    long total_size;                 /* 源文件总大小（字节） */
    long copied_size = 0;            /* 已复制的字节数 */
    int result = -1;                 /* 函数返回值，默认失败 */
    int dst_opened = 0;              /* 目标文件是否曾经成功打开 */
    int progress_active = 0;         /* 当前是否有未换行的进度输出 */

    if (src_path == NULL || dst_path == NULL) {
        fprintf(stderr, "源文件和目标文件路径不能为空\n");
        return -1;
    }

    if (same_file(src_path, dst_path)) {
        fprintf(stderr, "源文件和目标文件不能是同一个文件: '%s'\n", src_path);
        return -1;
    }

    /* 以只读二进制模式打开源文件 */
    src = fopen(src_path, "rb");
    if (src == NULL) {
        fprintf(stderr, "无法打开源文件 '%s'\n", src_path);
        goto cleanup;                /* 跳过后续步骤，直接清理并返回 */
    }

    /* 将文件指针移动到文件末尾，以便获取文件大小 */
    if (fseek(src, 0, SEEK_END) != 0) {
        fprintf(stderr, "无法获取源文件大小 '%s'\n", src_path);
        goto cleanup;
    }

    /* 获取当前文件指针位置，即文件的总大小 */
    total_size = ftell(src);
    if (total_size < 0) {
        fprintf(stderr, "无法获取源文件大小 '%s'\n", src_path);
        goto cleanup;
    }

    /* 将文件指针重新移动到文件开头，准备读取内容 */
    if (fseek(src, 0, SEEK_SET) != 0) {
        fprintf(stderr, "无法定位源文件 '%s'\n", src_path);
        goto cleanup;
    }

    /* 以只写二进制模式创建/覆盖目标文件 */
    dst = fopen(dst_path, "wb");
    if (dst == NULL) {
        fprintf(stderr, "无法打开目标文件 '%s'\n", dst_path);
        goto cleanup;
    }
    dst_opened = 1;

    /* 源文件为空（大小为 0）时直接显示 100% 进度 */
    if (total_size == 0) {
        printf("进度: 100%%\n");
    }

    /* 循环读取源文件内容并写入目标文件 */
    while (1) {
        /* 从源文件读取最多一个缓冲区的字节 */
        size_t bytes_read = fread(buffer, 1, sizeof(buffer), src);

        if (bytes_read > 0) {
            /* 将读取到的内容写入目标文件 */
            size_t bytes_written = fwrite(buffer, 1, bytes_read, dst);

            /* 写入字节数不一致说明写入失败 */
            if (bytes_written != bytes_read) {
                if (progress_active) {
                    putchar('\n');
                    fflush(stdout);
                    progress_active = 0;
                }
                fprintf(stderr, "写入目标文件失败 '%s'\n", dst_path);
                goto cleanup;
            }

            /* 累加已复制的字节数，并计算并输出进度百分比 */
            copied_size += (long)bytes_written;
            if (total_size > 0) {
                int percent = (int)(((long double)copied_size * 100.0L) /
                                    (long double)total_size);
                if (percent > 100) {
                    percent = 100;
                }
                printf("\r进度: %d%%", percent);     /* \r 表示回车回行首，覆盖旧进度 */
                fflush(stdout);                     /* 强制刷新输出缓冲区，立即显示进度 */
                progress_active = 1;
            }
        }

        /* 如果读取字节数小于缓冲区大小，说明已到达文件末尾 */
        if (bytes_read < sizeof(buffer)) {
            if (ferror(src)) {                      /* 判断读取是否发生错误 */
                if (progress_active) {
                    putchar('\n');
                    fflush(stdout);
                    progress_active = 0;
                }
                fprintf(stderr, "读取源文件失败 '%s'\n", src_path);
                goto cleanup;
            }
            break;                                  /* 正常到达文件末尾，结束循环 */
        }
    }

    /* 循环结束后再次显示 100% 进度并换行 */
    if (total_size > 0) {
        printf("\r进度: 100%%\n");
        progress_active = 0;
    }

    /* 显式关闭目标文件，并检查是否出错 */
    if (fclose(dst) != 0) {
        dst = NULL;
        fprintf(stderr, "关闭目标文件失败 '%s'\n", dst_path);
        goto cleanup;
    }
    dst = NULL;                                     /* 关闭成功，置空防止重复关闭 */

    result = 0;                                     /* 全部操作成功，标记成功 */

cleanup:
    if (progress_active) {
        putchar('\n');
        fflush(stdout);
    }
    /* 统一清理：若句柄不为 NULL 则关闭，避免资源泄漏 */
    if (dst != NULL) {
        fclose(dst);
    }
    if (result != 0 && dst_opened) {
        if (remove(dst_path) == 0) {
            fprintf(stderr, "复制失败，已删除不完整的目标文件 '%s'\n", dst_path);
        } else {
            fprintf(stderr, "复制失败，无法删除不完整的目标文件 '%s'\n", dst_path);
        }
    }
    if (src != NULL) {
        fclose(src);
    }
    return result;      /* 返回结果 */
}

int main(int argc, char *argv[])
{
    /* 参数个数校验：需要程序名 + 源文件路径 + 目标文件路径，共 3 个 */
    if (argc != 3) {
        fprintf(stderr, "用法: %s <源文件> <目标文件>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* 调用复制函数，若非 0 说明失败 */
    if (copy_file(argv[1], argv[2]) != 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;    /* 成功退出 */
}

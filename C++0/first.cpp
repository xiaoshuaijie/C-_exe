#include <iostream>
#include <limits>
#include <cstdint>

int main()
{
    std::cout << "=== 完整的大小和范围报告报告 ===" << std::endl;
    std::cout << std::endl;

    std::cout << "--- 基本整数类型sizeof汇总 ---" << std::endl;
    std::cout << "short:          sizeof " << sizeof(short) << " 字节, "
              << "min " << std::numeric_limits<short>::min() << ", "
              << "max " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "unsigned short: sizeof " << sizeof(unsigned short) << " 字节, "
              << "min " << std::numeric_limits<unsigned short>::min() << ", "
              << "max " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "int:            sizeof " << sizeof(int) << " 字节, "
              << "min " << std::numeric_limits<int>::min() << ", "
              << "max " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "unsigned int:   sizeof " << sizeof(unsigned int) << " 字节, "
              << "min " << std::numeric_limits<unsigned int>::min() << ", "
              << "max " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "long:           sizeof " << sizeof(long) << " 字节, "
              << "min " << std::numeric_limits<long>::min() << ", "
              << "max " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "unsigned long:  sizeof " << sizeof(unsigned long) << " 字节, "
              << "min " << std::numeric_limits<unsigned long>::min() << ", "
              << "max " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "long long:      sizeof " << sizeof(long long) << " 字节, "
              << "min " << std::numeric_limits<long long>::min() << ", "
              << "max " << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "unsigned long long: sizeof " << sizeof(unsigned long long) << " 字节, "
              << "min " << std::numeric_limits<unsigned long long>::min() << ", "
              << "max " << std::numeric_limits<unsigned long long>::max() << std::endl;

    std::cout << std::endl;
    std::cout << "--- <cstdint> 固定宽整数类型 ---" << std::endl;
    std::cout << "int8_t:         sizeof " << sizeof(int8_t) << " 字节, "
              << "min " << (int)std::numeric_limits<int8_t>::min() << ", "
              << "max " << (int)std::numeric_limits<int8_t>::max() << std::endl;
    std::cout << "uint8_t:        sizeof " << sizeof(uint8_t) << " 字节, "
              << "min " << (unsigned)std::numeric_limits<uint8_t>::min() << ", "
              << "max " << (unsigned)std::numeric_limits<uint8_t>::max() << std::endl;
    std::cout << "int16_t:        sizeof " << sizeof(int16_t) << " 字节, "
              << "min " << std::numeric_limits<int16_t>::min() << ", "
              << "max " << std::numeric_limits<int16_t>::max() << std::endl;
    std::cout << "uint16_t:       sizeof " << sizeof(uint16_t) << " 字节, "
              << "min " << std::numeric_limits<uint16_t>::min() << ", "
              << "max " << std::numeric_limits<uint16_t>::max() << std::endl;
    std::cout << "int32_t:        sizeof " << sizeof(int32_t) << " 字节, "
              << "min " << std::numeric_limits<int32_t>::min() << ", "
              << "max " << std::numeric_limits<int32_t>::max() << std::endl;
    std::cout << "uint32_t:       sizeof " << sizeof(uint32_t) << " 字节, "
              << "min " << std::numeric_limits<uint32_t>::min() << ", "
              << "max " << std::numeric_limits<uint32_t>::max() << std::endl;
    std::cout << "int64_t:        sizeof " << sizeof(int64_t) << " 字节, "
              << "min " << std::numeric_limits<int64_t>::min() << ", "
              << "max " << std::numeric_limits<int64_t>::max() << std::endl;
    std::cout << "uint64_t:       sizeof " << sizeof(uint64_t) << " 字节, "
              << "min " << std::numeric_limits<uint64_t>::min() << ", "
              << "max " << std::numeric_limits<uint64_t>::max() << std::endl;

    return 0;
}

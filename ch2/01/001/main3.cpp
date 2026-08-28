#include <iostream>

int main()
{
    int year, month, day;
    std::cout << "请输入年、月、日（用空格分割，例如 : 2024 2 29) : " << std::endl;
    if (!(std::cin >> year >> month >> day))
    {
        std::cout << "错误：输入格式无效" << std::endl;
        return 1;
    }

    if (year <= 0 || month < 1 || month > 12 || day < 1)
    {
        std::cout << "这个日期不合法" << std::endl;
        return 1;
    }

    int maxDay = 31;
    switch (month)
    {
    case 2:
        maxDay = ((year % 400 == 0) ||
                  (year % 4 == 0 && year % 100 != 0))
                     ? 29
                     : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDay = 30;
        break;
    }

    if (day > maxDay)
    {
        std::cout << "这个日期不合法" << std::endl;
        return 1;
    }

    std::cout << "这个日期合法" << std::endl;
    return 0;
}

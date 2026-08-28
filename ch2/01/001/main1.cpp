#include <iostream>
int main()
{
    int value = 0;
    std::cout << "请输入一个整数: " << std::endl;
    std::cin >> value;
    if (value > 0)
    {
        std::cout << value << "是正数" << std::endl;
    }
    else if (value < 0)
    {
        std::cout << value << "是负数" << std::endl;
    }
    else
    {
        std::cout << value << "是零" << std::endl;
    }

    return 0;
}
#include <iostream>

int main()
{
    int n = 0;
    std::cout << "输入一个正整数 N: ";
    if (!(std::cin >> n) || n < 2)
    {
        std::cout << "输入无效，请输入一个正整数！" << std::endl;
        return 1;
    }
    std::cout << "2" << "到" << n << "之间所有的素数: " << std::endl;
    for (int flag = 0, i = 2; i <= n; i++)
    {
        flag = 0;
        for (int j = 2; j <= i - 1; j++)
        {

            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
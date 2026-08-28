#include <iostream>

int main()
{
    int n = 0;
    std::cout << "输入一个正整数 N: ";
    if (!(std::cin >> n) || n < 1)
    {
        std::cout << "输入无效，请输入一个正整数！" << std::endl;
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i != 1) && (i != n))
            {
                if ((j != 1) && (j != n))
                {
                    std::cout << "   ";
                    continue;
                }
            }
            std::cout << " * ";
        }
        std::cout << std::endl;
    }
    return 0;
}
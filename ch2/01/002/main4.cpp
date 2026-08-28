#include <iostream>

int main()
{
    int n = 0;
    std::cout << "输入一个正奇数 N: ";

    if (!(std::cin >> n) || n <= 0 || n % 2 == 0)
    {
        std::cout << "输入无效，请输入一个正确的正奇数！" << std::endl;
        return 1;
    }

    const int middleRow = (n + 1) / 2;
    for (int row = 1; row <= n; ++row)
    {
        const int stars = row <= middleRow
                              ? 2 * row - 1
                              : 2 * (n - row) + 1;
        const int spaces = (n - stars) / 2;

        for (int column = 0; column < spaces; ++column)
        {
            std::cout << ' ';
        }

        for (int column = 0; column < stars; ++column)
        {
            std::cout << '*';
        }

        std::cout << std::endl;
    }

    return 0;
}

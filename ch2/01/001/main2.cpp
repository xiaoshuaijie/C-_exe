#include <iostream>

int main()
{
    int left = 0;
    int right = 0;
    char operation = 0;

    std::cout << "请输入表达式（如 3 + 5): " << std::endl;
    if (!(std::cin >> left >> operation >> right))
    {
        std::cout << "错误：输入格式无效" << std::endl;
        return 1;
    }

    switch (operation)
    {
    case '+':
        std::cout << left + right << std::endl;
        break;
    case '-':
        std::cout << left - right << std::endl;
        break;
    case '*':
        std::cout << left * right << std::endl;
        break;
    case '/':
        if (right == 0)
        {
            std::cout << "错误：除数不能为零" << std::endl;
            return 1;
        }
        std::cout << left / right << std::endl;
        break;
    default:
        std::cout << "错误：不支持的运算符" << std::endl;
        return 1;
    }

    return 0;
}

#include <iostream>
int &get_max(int a, int b)
{
    static int result = 0;
    result = (a > b) ? a : b;
    return result;
}

int main()
{
    int &m = get_max(3, 7);
    std::cout << m << "\n";
    return 0;
}
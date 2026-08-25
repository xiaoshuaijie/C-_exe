#include <iostream>

int main()
{
    std::cout << "=== C++: sizeof 表达式验证 ===" << std::endl;
    std::cout << "sizeof('A')   = " << sizeof('A') << std::endl;
    std::cout << "sizeof(true)  = " << sizeof(true) << std::endl;
    std::cout << "sizeof(3.14)  = " << sizeof(3.14) << std::endl;
    std::cout << "sizeof(3.14f) = " << sizeof(3.14f) << std::endl;
    std::cout << "sizeof(3.14L) = " << sizeof(3.14L) << std::endl;
    return 0;
}

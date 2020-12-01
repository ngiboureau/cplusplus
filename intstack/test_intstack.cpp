#include "intstack.h"
#include <iostream>

int main()
{
    IntStack stack = IntStack (5,4,2,7,3,74);
    stack.push(2);
    stack.print();
    std::cout << stack.pop() << std::endl;
    std::cout << stack.is_empty() << std::endl;
    stack.print();
    return 0;
}
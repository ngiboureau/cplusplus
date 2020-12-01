#include "intstack.h"
#include <iostream>

int main()
{
    IntStack stack = IntStack (1,4);
    stack.push(2);
    stack.print();
    std::cout << stack.pop() << std::endl;
    std::cout << stack.is_empty() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.is_empty() << std::endl;
    try
    {
        stack.pop();
    }
    catch(const char* e)
    {
        printf(e,"s");
    }
    std::cout << std::endl;
    return 0;
}
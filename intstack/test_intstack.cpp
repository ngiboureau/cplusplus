#include <iostream>
#include <vector>

std::vector<int>* init_stack()
{
    std::vector<int>* pi = new std::vector<int>;
    return pi;
}

void delete_stack(std::vector<int>* stack)
{
    delete stack;
}

void print_stack(std::vector<int> stack)
{
    std::cout << '[';
    for (int i = 0; i < stack.size(); i++)
        std::cout << stack[i] << ' ';
    std::cout << '[' << std::endl;
}

void push(std::vector<int>* tab, int i)
{
    (*tab).push_back(i);
    print_stack(*tab);
}

int pop(std::vector<int>* tab)
{
    int i = (*tab)[(*tab).size()-1];
    (*tab).pop_back();
    return i;
}
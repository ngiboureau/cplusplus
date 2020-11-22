#include <iostream>
#include <vector>
#include <stdarg.h>

class IntStack
{
    public:
        
        IntStack (int a, ...) //a est le nombre de valeurs initiales
        {
            std::vector<int>* init = new std::vector<int>;
            int i=0,j=a;
            va_list ap;
            va_start(ap,a);
            int c=0;
            while (i<j)
            {
                c=va_arg(ap,int);
                init->push_back(c);
                i++;
            }
            va_end(ap);
            stack = init;
        }//renvoi un vecteur de taille a composé des valeurs mises en argument après a

        ~IntStack ()
        {
            delete stack;
        }
        void print()
        {
            std::cout << '[';
            for (int i = 0; i < stack->size(); i++)
                std::cout << (*stack)[i] << ' ';
            std::cout << '[' << std::endl;
        }

        void push(int i)
        {
            stack->push_back(i);
        }

        int pop()
        {
            int i = (*stack)[stack->size()-1];
            stack->pop_back();
            return i;
        }

        bool is_empty()
        {
            return stack->size()==0;
        }

    private:
    
        std::vector<int>* stack;
};
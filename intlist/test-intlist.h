#include "intlist.h"
#include <cstdlib>
#include <iostream>

inline void test_default_constructor_1() 
{
    std::cout << "test default constructor on empty list";
    IntList list;
    std::cout << std::boolalpha <<  " *** " << ((list.size() == 0) and (list.is_empty())) << std::endl;
}

inline void test_add_front_1() 
{
    std::cout << "test add front one element with value";
    IntList list;
    int e1 = rand();
    list.add_front(e1);
    std::cout << std::boolalpha << " *** " <<  (list.get_element_at(0) == e1) << std::endl;
}

inline void test_add_front_2() 
{
    std::cout << "test add front n elements with values";
    IntList list;
    int n = rand()%10;
    int tab [n];
    for (int i = 0; i < n; i++) 
    {
        tab[i] = rand();
        list.add_front(tab[i]);
    }
    for (int i = n-1; i >= 0; i--) 
    {
        if (tab[(n-1)-i] != list.get_element_at(i)) 
        {
            std::cout << " *** " << "bad element value" << std::endl;
            return;
        }
    }
    std::cout << " *** " << "true" << std::endl;
}

inline void test_add_back_1() 
{
    std::cout << "test add back one element with value";
    IntList list;
    int e1 = rand();
    list.add_back(e1);
    std::cout << std::boolalpha << " *** " <<  (list.get_element_at(0) == e1) << std::endl;
}

inline void test_add_back_2() 
{
    std::cout << "test add back n elements with values";
    IntList list;
    int n = rand()%10;
    int tab [n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand();
        list.add_back(tab[i]);
    }
    for (int i = 0; i < n; i++) 
    { 
        if (tab[i] != list.get_element_at(i)) 
        {
            std::cout << " *** " << "bad element value";
            return;
        }
    }
    std::cout << " *** " << " true" << std::endl;
}

inline void test_size_1()
{
    std::cout << "test size of empty list";
    IntList list;
    std::cout << std::boolalpha << " *** " <<  (list.size() == 0) << std::endl;
}

inline void test_size_2() 
{
    std::cout << "test size one element";
    IntList list;
    int e = rand();
    list.add_front(e);
    std::cout << std::boolalpha << " *** " <<  ((list.size() == 1) and (not list.is_empty())) << std::endl;
}

inline void test_size_3() 
{
    std::cout << "test size of list with n elements";
    IntList list;
    int n = rand()%100;
    for (int i = 0; i < n; i++) 
    {
        int e = rand();
        list.add_front(e);
    }
    std::cout << std::boolalpha << " *** " <<  (list.size() == n) << std::endl;
}

inline void test_search_1()
{
    std::cout << "test search true";
    IntList list;
    int e = rand();
    list.add_front(e);
    std::cout << std::boolalpha << " *** " << list.search(e) << std::endl;
}

inline void test_search_2()
{
    std::cout << "test search false";
    IntList list;
    int e = rand();
    int f = e+1;
    list.add_front(e);
    std::cout << std::boolalpha << " *** " << not list.search(f) << std::endl;
}

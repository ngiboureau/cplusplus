#include <iostream>

class IntCell
{
    friend class IntList;

    private:
        IntCell(int v): value(v) {}
        int value = 0;
        IntCell* av = nullptr;
        IntCell* ap = nullptr;
};

class IntList
{
    public:

        IntList() {}

        ~IntList()
        {
            IntCell* pi = p;
            while (pi != d)
            {   
                pi = pi->ap;
                delete pi->av;
            }
            delete pi; 
        }

        void add_front(int i)
        {
            IntCell* cell = new IntCell (i);
            cell->ap = p;
            if (p != nullptr)
                p->av = cell;
            p = cell;
            if (d == nullptr) 
                d = cell;            
        }

        void add_back(int i)
        {
            IntCell* cell = new IntCell (i);
            cell->av = d;
            if (d != nullptr)
                d->ap = cell;
            d = cell;
            if (p == nullptr)
                p = cell;
        }

        void remove_front()
        {
            if (p != nullptr)
            {
                if (p != d)
                {
                    p = p->ap;
                    delete p->av;
                    p->av = nullptr;
                }
                else
                {
                    delete p;
                    p = nullptr;
                    d = nullptr;
                }   
            }
        }

        void remove_back()
        {
            if (d != nullptr)
            {
                if (p != d)
                {
                    d = d->av;
                    delete d->ap;
                    d->ap = nullptr;
                }
                else
                {
                    delete d;
                    p = nullptr;
                    d = nullptr;    
                }    
            }
        }

        bool search(int i)
        {
            bool s = false;
            IntCell* pi = p;
            while (pi != nullptr)
            {
                if (pi->value == i)
                    s = true;
                pi = pi->ap;
            }
            return s;
        }

        void remove(int i)
        {
            IntCell* pi = p;
            while (pi->value != i and pi != d)
            {
                pi = pi->ap;    
            }
            if (pi != d and pi != p)
            {
                (pi->av)->ap = pi->ap;
                (pi->ap)->av = pi->av;
                delete pi;
            }
            else if (pi == p)
            {
                if (p != d)
                {
                    p = p->ap;
                    delete p->av;
                }
                else if (d->value == i)
                {
                    delete d;
                    p = nullptr;
                    d = nullptr;        
                }
            }
            else if (d->value == i) 
            {
                d = d->av;
                delete d->ap;
            }
        }

        void print()
        {
            std::cout << '{';
            IntCell* pi = p;
            while (pi != nullptr)
            {
                std::cout << pi->value << ' ';
                pi = pi->ap;
            }
            std::cout << '}' << std::endl;
        }

        int size()
        {
            IntCell* pi = p;
            int s = 0;
            while (pi != nullptr)
            {
                s++;
                pi = pi->ap;
            }
            return s;
        }

        bool is_empty()
        {
            return (p == nullptr);
        }

        int get_element_at(int i)
        {
            IntCell* pi = p;
            int s = 0;
            while (pi != nullptr and s != i)
            {
                s++;
                pi = pi->ap;
            }
            if (pi == nullptr)
                throw ("no element at this indexation");
            return pi->value;
        }

    private:

        IntCell* p = nullptr;
        IntCell* d = nullptr;
};
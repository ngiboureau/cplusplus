#include <iostream>
#include <vector>
#include <stdarg.h>

class IntStack
{
    public:

        IntStack (int a, ...) //a est le nombre de valeurs initiales
        {
	  // vr: ne crée pas un nouvel objet init puisque l'objet
	  // stack de type std::vector<int> existe désormais dès
	  // l'entrée dans le constructeur (tu aurais même pu lui
	  // passer des arguments dans la liste d'initialisation)

	    std::vector<int> init;
            int i=0,j=a;
            va_list ap;
            va_start(ap,a);
            int c=0;
            while (i<j)
            {
                c=va_arg(ap,int);
                init.push_back(c);
                i++;
            }
            va_end(ap);
	    // vr: dans la ligne de code suivante, tu recopies l'objet
	    // init dans l'objet stack existant, donc ton code:
	    // 1) doit détruire l'objet stack
	    // 2) créer un autre objet stack par copie de init
	    // 3) détruire init qui est local au constructeur
	    // c'est beaucoup de travail inutile
	    stack = init;
        }//renvoi un vecteur de taille a composé des valeurs mises en argument après a

        void print()
        {
            std::cout << '[';
	    // vr: puisque tu utilises un std::vector, il comporte un
	    // type à utiliser pour la taille se son container qui est
	    // size_type (du type template std::vector<int>)
            for (std::vector<int>::size_type i = 0; i < stack.size(); i++)
                std::cout << stack[i] << ' ';
            std::cout << '[' << std::endl;
        }

        void push(int i)
        {
	  // vr: avec la solution des std::vector que tu as choisie tu
	  // ne peux effectivement pas avoir de pile pleine ni de
	  // création d'une pile avec une taille erronée
            stack.push_back(i);
        }

        int pop()
        {
            if (stack.size()==0)
                throw "cannot pop an empty file";
            int i = stack[stack.size()-1];
            stack.pop_back();
            return i;
        }

  // vr: implémente is_full
        bool is_empty()
        {
            return stack.size()==0;
        }

    private:
  // vr: mets un objet directemetn comme cela tu évites de faire new
  // et delete std::vector<int> stack;
        std::vector<int> stack;
};

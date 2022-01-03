#include <iostream>
using namespace std;

struct nodo
{
	int valor;
	nodo* next;
	nodo(int v, nodo* n = NULL)
	{
		valor = v;
		next = n;
	}
};

class fun
{
	int num;
public:
	fun(int x) : num(x) {};
	nodo* operator()()
	{
        nodo*numero =nullptr;
        nodo*tmp= nullptr;
		while(num>=0){
            if(num%2){
                tmp = new nodo(1,tmp);
                tmp->next = numero;
                numero = tmp;
                num = num/2;tmp = nullptr;
            }
            else{
                tmp = new nodo(0,tmp);
                tmp->next = numero;
                numero = tmp;
                num = num/2;tmp = nullptr;
            }
        }
        return numero;
	}

};

void print(nodo* head)
{
	for (nodo* p = head; p; p = p->next)
		cout << p->valor;

}

void clean(nodo* head)
{
	nodo* tmp, * p = head;
	while (p)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
	
}

template<class T>
nodo* convertir(T funcion)
{
	nodo* p=NULL;
	for (nodo* t = funcion(); t; t=funcion())
	{
		t->next = p;
		p = t;
	}
	return p;
}



int main()
{
	int A[5] = { 28,35,79,150,255 };
	nodo* bin = NULL;
	
	for (int* p = A; p < A + 5; p++)
	{
		bin = convertir(fun(*p));
		cout << *p << " en binario es ";
		print(bin);
		cout<<endl;
		clean(bin);
	}
}

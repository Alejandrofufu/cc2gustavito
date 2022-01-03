#include <iostream>

using namespace std;

template <class T>
struct nodo
{
    T dato;
    nodo<T> *next;

    nodo(T d, nodo<T> *n = nullptr)
    {
        dato = d;
        next = n;
    }
};

template<class T>
class pila
{
public:
    nodo<T> *top =nullptr;

    void push(T elem)
    {
        
            top = new nodo<T>(elem,top);
        
    }

    T pop()
    {
        
            nodo<T>* tmp =top;
            top = top->next;
            T valor = tmp ->dato;
            delete tmp;
            return valor;
        
    }

    ~pila()
    { 
        while (top)
            pop();
    }
};


int main()
{
    int valores[5] = {3,8,25,37,1};
    pila<int> st;

    for (int i = 0; i < 5; i++)
        st.push(valores[i]);

    while (st.top)
        cout << st.pop() << endl;
    
}

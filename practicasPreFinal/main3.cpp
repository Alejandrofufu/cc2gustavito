#include <iostream>

using namespace std;

struct asc
{
    bool operator()(int a, int b)
    {
        return a <= b;
    }
};


struct desc
{
    bool operator()(int a, int b)
    {
        return a >= b;
    }
};


class nodo
{
public:
    int valor;
    nodo* next;
    nodo(int v, nodo* n = nullptr)
    {
        valor = v;
        next = n;
    }
};
template<class T>
class LE
{
    nodo* head = nullptr;
    T comp;
public:
    void print();
    bool find(int v, nodo*& pos);
    void add(int v);
    void del(int v);
    ~LE();
};

template<class T>
void LE<T>::print()
{
    cout << "Head->";
    for (nodo* p = head; p; p = p->next)
        cout << p->valor << "->";
    cout << "NULL" << endl;
}

template<class T>
bool LE<T>::find(int v, nodo*& pos)
{
    bool encontrado = false;
    pos = nullptr;

    for (nodo* p = head; p && comp(p->valor, v); p = p->next)
    {
        if (p->valor == v)
        {
            encontrado = true;
            break;
        }
        pos = p;
    }
    return encontrado;
}

template<class T>
void LE<T>::add(int v)
{
    nodo* pos_ant;
    if (!find(v, pos_ant))
    {
        if (pos_ant)
            pos_ant->next = new nodo(v, pos_ant->next);
        else
            head = new nodo(v, head);
    }
}

template<class T>
void LE<T>::del(int v)
{
    nodo* pos_ant, * pos_del;
    if (find(v, pos_ant))
    {
        if (pos_ant)
        {
            pos_del = pos_ant->next;
            pos_ant->next = pos_del->next; //pos_ant->next = pos_ant->next->next;
            delete pos_del;
        }
        else
        {
            pos_del = head;
            head = pos_del->next; //head = head->next;
            delete pos_del;
        }
    }
}

template<class T>
LE<T>::~LE()
{
    /*cout<<"Destruyendo lista..."<<endl;
    while(head)
   {
     cout<<head->valor<<" ";
      del(head->valor);
   }
   cout<<endl<<"Lista destruida";*/
    while (head)
        del(head->valor);
}

int main() {
    //LE lista;
    //LE<asc> lista;
    LE<desc> lista;

    lista.print();
    lista.add(5);
    lista.print();
    lista.add(1);
    lista.print();
    lista.add(3);
    lista.print();
    lista.add(7);
    lista.print();
    lista.add(3);
    lista.print();

    lista.del(3);
    lista.print();
    lista.del(3);
    lista.print();
    lista.del(7);
    lista.print();
    lista.del(1);
    lista.print();
    lista.del(5);
    lista.print();

}

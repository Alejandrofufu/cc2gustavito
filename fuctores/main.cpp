#include <iostream>

using namespace std;

struct asc
{
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

struct desc
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

struct nodo
{
    int valor;
    nodo* next;
    nodo(int v, nodo* n = nullptr)
    {
        valor = v; next = n;
    }
};

void crear(int* p, nodo*& lista)
{
    lista = new nodo(*p);
    p++;
    for (nodo* n = lista; *p > 0; p++, n = n->next)
        n->next = new nodo(*p);

}

void print(nodo* lista)
{
    cout << "lista -> ";
    for (; lista; lista = lista->next)
        cout << lista->valor << " -> ";
    cout << "NULL" << endl;
}

template<typename T>
void ordenar(nodo*& lista, T comp)
{
    nodo* l=lista;//iterador 
    nodo* j = lista,*ox;//mayor/menor  iterador de tmp
    for (; l; l = l->next) {
        if (!comp(j->valor, l->valor)) { j = l;}  
    }
    nodo* tmp = lista;// lista temporal
    if (lista != j) { 
        for (l = lista; l->next!=j; l = l->next) {}
        l->next = l->next->next;
        lista = j;
    }
    else {
        tmp = tmp->next;
    }
    ox = lista;
    while (tmp) {
        j = tmp;
        for (l = tmp; l; l = l->next) {
            if (!comp(j->valor, l->valor)) { j = l; }
        }
        if (j == tmp) {
            tmp = tmp->next;
            ox->next = j;
            ox = ox->next;
        }
        else {
            for (l = tmp; l->next != j; l = l->next) {}
            l->next = l->next->next;
            ox->next = j;
            ox = ox->next;
        }
    }
}


int main() {
    
    int A[] = { 7, 7, 27, 7, 12, 9, 18, 9, 8, 7, -1 };
    nodo* miLista;

    crear(A, miLista);
    print(miLista);

    //orden asc
    ordenar(miLista, asc());
    print(miLista);

    //orden desc
    ordenar(miLista, desc());
    print(miLista);

}

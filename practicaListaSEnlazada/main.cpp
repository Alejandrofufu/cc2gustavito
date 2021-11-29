#include <iostream>
using namespace std;

struct nodo
{
    int valor;
    nodo *next;
    nodo(int v,nodo* n = 0)
    {
        valor = v;
        next = n;
    }
};

void ArrToLe(int *Arr, int x,nodo*& head)
{
    nodo *tmp;
    head = new nodo(Arr[0]);
    tmp = head;
    for(int i=1;i<x;i++)
    {
        tmp->next = new nodo(Arr[i]);
        tmp = tmp->next;
    }       

}

void PrintLe(nodo *head)
{
    cout<<"HEAD->";
    for(nodo *p=head; p; p=p->next)
        cout<<p->valor<<"->";
    cout<<"NULL"<<endl;
}

void mezcla(nodo *&a, nodo *&b)
{
    nodo *A = a,*B = b;
    nodo *tmp = nullptr;
    if(A->valor < B->valor){
        tmp = A;
        A = A->next;
    }
    else{
        tmp = B;
        B = B->next;
    }
    while(A && B){
        if(A->valor < B->valor){
            tmp->next = A;
            A = A->next;
            tmp = tmp->next;
        }
        else{
            tmp->next = B;
            B = B->next;
            tmp = tmp->next;
        }
    }
    if(!A){
        tmp->next = B;
        if(a->valor>b->valor)a=b;
        b=A;
    }
    else{
        tmp->next = A;
        if(a->valor>b->valor)a=b;
        b = B;
    }
}



int main() {

   int Arr1[10] = {5,8,25,30,35,41,48,53,67,76};
   int Arr2[5] = {3,4,38,57,99};
   nodo *A, *B;
   ArrToLe(Arr1,10,A);
   ArrToLe(Arr2,5,B);
   cout<<"Lista A"<<endl;
   PrintLe(A);
   cout<<"Lista B"<<endl;
   PrintLe(B);
   mezcla(A,B);
   cout<<"--- DESPUES MEZCLA ---------"<<endl;
   cout<<"Lista A"<<endl;
   PrintLe(A);
   cout<<"Lista B"<<endl;
   PrintLe(B);   
}
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
   //TO DO
}

int main() {

   int Arr1[10] = {5,8,25,30,35,41,48,53,67,76};
   int Arr2[5] = {3,23,38,57,99};
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
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
   nodo*tmp;
   nodo*p=a;
   nodo*q=b;
   if(p->valor<q->valor){
      tmp = p;p=p->next;
   }
   else{
      tmp = q;q = q->next;
   }
   while(p&&q){
      if(p->valor<q->valor){
         tmp->next = p;
         p=p->next;
      }
      else{
         tmp->next = q;
         q=q->next;
      }
      tmp=tmp->next;
   }
   if(!p){
      tmp->next = q;
      if(b->valor<a->valor)a = b;
      b = p;
   }
   else{
      tmp->next = p;
      if(b->valor<a->valor)a=b;
      b=q;
   }
}

int main() {

   int Arr1[10] = {3,8,25,30,35,41,48,53,67,76};
   int Arr2[5] = {5,23,38,57,99};
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
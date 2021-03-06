#include <iostream>

using namespace std;

struct asc
{
  bool operator()(int a, int b)
  {return a<b;}
};

struct desc
{
  bool operator()(int a, int b)
  {return a>b;}
};
template<class T>
class nodo
{
  public:
  int valor;
  nodo<T>* next;
  nodo(int v, nodo<T>* n=nullptr)
  { 
    valor = v;
    next = n;
  }
};
template<class T,typename O>
class LE
{
  nodo<T>* head=nullptr;

  public:
  void print();
  bool find(int v,nodo<T> *&pos,O comp);
  void add(int v);
  void del(int v);
  ~LE();
};

template<class T>
void LE<class T>::print()
{
  cout<<"Head->";
  for(nodo* p=head;p;p = p->next)
      cout<<p->valor<<"->";
  cout<<"NULL"<<endl;   
}

template<class T,typename O>
bool LE<class T,typename O>::find(int v, nodo<T> *&pos,O comp)
{
  bool encontrado =false;
  pos = nullptr;

  for(nodo<T>* p =head;p && p->valor<=v;p=p->next)
  {
    if(p->valor == v)
      {
        encontrado = true;
        break;
      }
    pos = p;
  }
  return encontrado;
}
template<class T,typename O>
void LE::add(int v)
{
  nodo* pos_ant;
  if(!find(v,pos_ant))
  {
     if(pos_ant)
       pos_ant->next = new nodo(v,pos_ant->next);
     else
      head = new nodo(v,head);
  }
}

void LE::del(int v)
{
  nodo *pos_ant,*pos_del;
  if(find(v,pos_ant))
  {
    if(pos_ant)
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

LE::~LE()
{
  /*cout<<"Destruyendo lista..."<<endl;
  while(head)
 { 
   cout<<head->valor<<" ";  
    del(head->valor);
 }
 cout<<endl<<"Lista destruida";*/
 while(head)
   del(head->valor);
}

int main() {
  LE lista;
  //LE<asc> lista;
  //LE<desc> lista;
  
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

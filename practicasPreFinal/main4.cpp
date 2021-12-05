#include <iostream>

using namespace std;
template<class T>
struct asc
{
  bool operator()(T a, T b)
  {return a<=b;}
};
template<class T>
struct desc
{
  bool operator()(T a, T b)
  {return a>=b;}
};

template<class T>
class nodo
{
  public:
  T valor;
  nodo<T>* next;
  nodo(T v, nodo<T>* n=nullptr)
  { 
    valor = v;
    next = n;
  }
};

template<class T,class O>
class LE
{
  nodo<T>* head=nullptr;
  O comp;
  public:
  void print();
  bool find(T v,nodo<T> *&pos);
  void add(T v);
  void del(T v);
  ~LE();
};

template<class T,class O>
void LE<T,O>::print()
{
  cout<<"Head->";
  for(nodo<T>* p=head;p;p = p->next)
      cout<<p->valor<<"->";
  cout<<"NULL"<<endl;   
}

template<class T,class O>
bool LE<T,O>::find(T v, nodo<T> *&pos)
{
  bool encontrado =false;
  pos = nullptr;

  for(nodo<T>* p =head;p && comp(p->valor,v);p=p->next)
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

template<class T,class O>
void LE<T,O>::add(T v)
{
  nodo<T>* pos_ant;
  if(!find(v,pos_ant))
  {
     if(pos_ant)
       pos_ant->next = new nodo<T>(v,pos_ant->next);
     else
      head = new nodo<T>(v,head);
  }
}

template<class T,class O>
void LE<T,O>::del(T v)
{
  nodo<T> *pos_ant,*pos_del;
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

template<class T,class O>
LE<T,O>::~LE()
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
  //LE lista;
  //LE<int,asc<int>> lista;
  LE<int,desc<int>> lista;
  
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

  cout<<"------------------------"<<endl;

  //LE<char,asc<char>> listaChar;
  LE<char,desc<char>> listaChar;

  
  
  listaChar.print();
  listaChar.add('g');
  listaChar.print();
  listaChar.add('a');
  listaChar.print();
  listaChar.add('d');
  listaChar.print();
  listaChar.add('z');
  listaChar.print();
  listaChar.add('d');
  listaChar.print();

  listaChar.del('d');
  listaChar.print();
  listaChar.del('d');
  listaChar.print();
  listaChar.del('z');
  listaChar.print();
  listaChar.del('a');
  listaChar.print();
  listaChar.del('g');
  listaChar.print();
  
}


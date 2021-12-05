#include <iostream>

using namespace std;

 struct ParXY
{ 

  int x;
  int y;
  ParXY(int a, int b): x(a), y(b) {};
};

class Pendiente
{
  ParXY Origen;

  public:
  Pendiente(ParXY a):Origen(a) {};
  void operator()(ParXY final){
    cout<<(final.y-Origen.y)/(final.x-Origen.x)<<endl;
  }
};

template<class O,class T, int a, int b>
class Calcular
{
  O op = O(T(a,b));
  
  public:
  Calcular(){};
  void operator()(T *f,T *f2){
    while(f<=f2){
      op(*f);
      f++;
    }
  }

};

int main()
{
  ParXY xy[6] = { ParXY(3,3),  ParXY(-1,3), ParXY(3,9),  ParXY(-3,-9), ParXY(8,-15), ParXY(4,9) };

  Calcular<Pendiente,ParXY,1,1> Calc;
  
  Calc(&xy[0],&xy[5]);

}


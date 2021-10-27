#include <iostream>

using namespace std;

void fibonacci(int *A)
{
	   *A = *(A-1) + *(A-2);
}

void factorial(int *A)
{
	   *A = *A * *(A-1);
}

void procesa(int *lmt[2],void (*Oper)(int*))
{
	for(int *p = *lmt; p <= *(lmt+1); p++)
		Oper(p);
}

void imprimir(int *ini, int *fin)
{
	for(int *p=ini; p<=fin; p++)
		cout<<*p<<" ";
	cout<<endl;
}

int main() {
    int Arr[2][8] = {{0,1,0,0,0,0,0,0},{1,2,3,4,5,6,7,8}};
	void (*pf[2])(int *) = {fibonacci, factorial};
	int *limite[2][2] = {{&Arr[0][2],&Arr[0][7]},{&Arr[1][1],&Arr[1][7]}};

	cout<<"Matriz antes de proceso"<<endl;
    for(int i=0; i<2; i++)
	{
		imprimir(Arr[i],Arr[i]+7);
	}

    for(int i=0; i<2; i++)
		procesa(limite[i],pf[i]);

	cout<<"Matriz despues de proceso"<<endl;
    for(int i=0; i<2; i++)
	{
		imprimir(Arr[i],Arr[i]+7);
	}
	
    return 0;
}
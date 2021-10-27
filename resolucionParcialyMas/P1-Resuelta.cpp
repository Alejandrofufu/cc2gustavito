#include <iostream>

using namespace std;

void fibonacci(int *ArrEnt, int ArrTam)
{
	for(int *A = ArrEnt; A < ArrEnt + ArrTam-2; A++)
	   *(A+2) = *(A+1) + *A;
}

int main() {
    int Arr[10];
	Arr[0] = 0;
	Arr[1] = 1;

	fibonacci(Arr,10);

	for(int *p = Arr; p < Arr+10; p++)
		cout<<*p<<" ";
	cout<<endl;	
    return 0;
}
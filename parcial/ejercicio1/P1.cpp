#include <iostream>

using namespace std;

void fibonacci(int *ArrEnt, int ArrTam)
{
   for(int *i = ArrEnt+2;i<ArrEnt+ArrTam;i++){
		   *i=*(i-1)+*(i-2);
   }
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
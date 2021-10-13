#include "iostream"
using namespace std;

int suma(int a,int b){
    return a+b;
}
int resta(int a,int b){
    return a-b;
}
int main(){
    int (*p)(int,int);
    int (*q[3])(int,int);

    //p = suma;
    q[0] = suma;
    q[1] = resta;

    

    return 0;
}
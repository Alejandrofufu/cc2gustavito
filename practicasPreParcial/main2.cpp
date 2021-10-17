#include <iostream>
using namespace std;
int imprimir(char*a){
    for(;*a;a++){
        cout<<*a;
    }cout<<"\n";
}
int comparar(char* CadenaA, char * Cadenab){
    int aux=0,aux2=0;
    for(;*CadenaA;){
        aux += (int)*CadenaA;
        CadenaA++;
    }
    for(;*Cadenab;){
        aux2 += (int)*Cadenab;
        Cadenab++;
    }
    if(aux<aux2)
        return 1;
    else if(aux>aux2)
        return -1;
    else
        return 0;
}
int main(){
    char a[10] = "comoestas";
    char b[10] = "comoes";
    imprimir(a);
    imprimir(b);
    cout<<"\n"<<comparar(a,b);
    return 0;
}
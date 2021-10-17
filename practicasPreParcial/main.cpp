#include "iostream"
using namespace std;
void imprimir(int *a,int size){
    for(int i = 0;i<size;i++,a++){
        cout<<*a<<",";
    }cout<<"\n";
}
void blanquear(int *a,int size){
    for(int i = 0;i<size;i++,a++){
        *a = 0;
    }
}
void mezclar(int *origenA,int *origenB,int *Destino){
    while(*origenA!=-1|| *origenB!=-1 ){
        if(*origenA<*origenB){
            *Destino= *origenA;
            origenA++;Destino++;
            if(*origenA == -1){
                while(*origenB!=-1){
                    *Destino = *origenB;
                    Destino++;origenB++;
                }
            }
        }
        else{
            *Destino = *origenB;
            origenB++;Destino++;
            if(*origenB == -1){
                while(*origenA!=-1){
                    *Destino = *origenA;
                    Destino++;origenA++;
                }
            }
        }
    }
}
int main(){
    int a[9] = {10,13,15,21,35,65,75,85,-1};
    int b[10] = {12,14,26,24,65,68,76,78,98,-1};
    int c[19];
    imprimir(a,9);
    imprimir(b,10);
    blanquear(c,19);
    imprimir(c,19);
    mezclar(a,b,c);
    imprimir(c,19); 

    return 0;
}
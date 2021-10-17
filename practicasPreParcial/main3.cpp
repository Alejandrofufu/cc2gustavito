#include "iostream"
using namespace std;
void imprimir(long *a,long size){
    for(long i = 0;i<size;i++,a++){
        cout<<*a<<",";
    }cout<<"\n";
}
void swap(long *a,long *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}
void merge(long *arrimpar,long *arrpar){
    long *fin = arrimpar+(arrpar-arrimpar)*2;
    while(arrimpar<arrpar &&arrpar<fin){ 
        if(*arrimpar<*arrpar){
            arrimpar++;
        }
        else{
            swap(arrimpar,arrpar);
            arrimpar++;
            for(long *aux = arrimpar;aux<arrpar;aux++)
                swap(aux,arrpar);
            arrpar++;
            
        }
    }
}
int main(){
    long a[10] = {3,7,9,11,15,2,4,6,8,10};
    imprimir(a,10);
    long *impar = a;
    long *par = a+5;
    merge(impar,par);
    cout<<"ordenado:\n";
    imprimir(a,10);

    return 0;
}
#include "iostream"
#include<cstdlib>
#include<ctime>
using namespace std;

void imprimir(int (*A)[3]){
    cout<<"\n";
    int *a = *A;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++,a++){
            cout<<*a<<",";
        }cout<<"\n";
    }
}
void numrand(int (*arr)[3],int sizeI){
    int *pt = *arr;
    for(int i = 0;i<sizeI*3;i++){
        *pt = 1+rand()%15;pt++;
    }
}
void Multi(int (*A)[3],int (*B)[3], int (*C)[3]){
    int *p,*q,*r;
    p = *A;q=*B;r=*C;
    while(p<=*(A+3)){
        if(r==*(C+1)){
            r-=3;p++;
        }
        if(q == *(B+3)){
            q=*B;r=*(C+1);C++;
        }
        *r = *r +(*p)*(*q);
        q++;r++;
    } 
}

int main(){
    int a[3][3];
    int b[3][3];
    int c[3][3]= {{0,0,0},{0,0,0},{0,0,0}};
    srand(time(NULL));
    numrand(a,3);
    numrand(b,3);
    imprimir(a);
    imprimir(b);
    Multi(a,b,c);
    imprimir(c);
    return 0;
}
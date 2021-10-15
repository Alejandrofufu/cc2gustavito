#include "iostream"
#include<cstdlib>
#include<ctime>
using namespace std;

void imprimir(int (*A)[3][3]){
    int (*b)[3] = *A;   
    int *a = *b;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++,a++){
                cout<<*a<<",";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}
void numrand(int (*arr)[3],int sizeI){
    int *pt = *arr;
    for(int i = 0;i<sizeI*3;i++){
        *pt = rand()%2;pt++;
    }
}

void Multi(int (*Arr)[3][3]){
    int (*A)[3] = *Arr;int (*B)[3] = *Arr;int (*C)[3] = *Arr;B=B+3;C=C+6;
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
    int a[3][3][3]={
        {{0,0,0},{0,0,0},{0,0,0}},
        {{0,0,0},{0,0,0},{0,0,0}},
        {{0,0,0},{0,0,0},{0,0,0}}
    };
    srand(time(NULL));
    int (*A)[3] = *a;int (*B)[3] = *a;B=B+3;numrand(A,3);numrand(B,3);
    imprimir(a);
    Multi(a);
    cout<<"multiplicado:\n";
    imprimir(a);
    return 0;
}
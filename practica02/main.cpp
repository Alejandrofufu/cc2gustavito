#include "iostream"
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
    int a[3][3]={
        {1,2,3},{4,5,6},{7,8,9}
    };
    int b[3][3] = {
        {2,2,2},{3,3,3},{8,8,8}
    };
    int c[3][3] = {
        {0,0,0},{0,0,0},{0,0,0}
    };
    imprimir(a);
    imprimir(b);
    Multi(a,b,c);
    imprimir(c);
    return 0;
}
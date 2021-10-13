#include "iostream"
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
        {{1,2,3},{4,5,6},{7,8,9}},
        {{9,8,7},{6,5,4},{3,2,1}},
        {{0,0,0},{0,0,0},{0,0,0}}
    };
    imprimir(a);
    Multi(a);
    cout<<"multiplicado:\n";
    imprimir(a);
    return 0;
}
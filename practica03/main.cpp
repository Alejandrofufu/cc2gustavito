#include "iostream"
using namespace std;

void imprimir(int *a,int size){
    for(int i = 0;i<size ;i++,a++){
        cout<<*a<<",";
    }
    cout<<"\n";
}
void mezcla(int *a,int*b,int*c,int size){// size es el tamaño de a y b 
    int *finA = a+size/2;int *finB = b+size/2;
    for(int i=0;i<size;i++){
        if(a == finA){
            for(;i<size;i++,c++,b++){
                *c=*b;
            }
        }
        else if(b == finB){
            for(;i<size;i++,c++,a++){
                *c=*a;
            }
        }
        else{
            if(*a<*b){
                *c = *a;
                a++;c++;
            }
            else{
                *c = *b;
                c++;b++;
            }
        }
    }
}

void swap(int *a,int *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}
void  mezcla2(int *a,int *b){
    int *fin = a+(b-a)*2;
    while(a<b && b<fin){
        if(*a<*b){a++;
            if(a==b)b++;
            }
        else{
            if(*(b+1)<*a && *(b+1)<*b){
                swap((b+1),a);a++;
                if(a==b)b++;
            }
            else{
                swap(b,a);a++;
                if(a==b)b++;
            }
        }
    }
}
void  mezcla3(int *a,int *b){
    int *fin = a+(b-a)*2;
    while(a<b && b<fin){
        if(*a<*b){a++;}
        else{
            swap(a,b);
            a++;
            for(int *r = a;r<b;r++)
                swap(r,b);
            b++;
            
        }
    }

}
int main(){
    int a[5]={3,7,9,11,15};
    int b[5] = {2,4,6,8,10};
    int c[10] ={0,0,0,0,0,0,0,0,0,0};
    //int d[10] ={9,11,13,15,17,4,12,18,20,24};    
    //int d[10] ={3,7,9,11,15,2,4,6,8,10};

    
    imprimir(a,5);
    imprimir(b,5);
    mezcla(a,b,c,10);
    imprimir(c,10);/*
    int *a = &d[0];
    int *b = &d[5];
    imprimir(d,10);
    cout<<"\nlista ordenada: \n";
    mezcla3(a,b);
    imprimir(d,10);*/
    return 0;
}
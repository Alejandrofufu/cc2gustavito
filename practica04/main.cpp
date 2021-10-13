#include "iostream"
#include <ctime>
using namespace std;
// Alejandro joel gonzales Huamani

void euclides(int a,int b,int &c){
    int aux;int r = 0;
    if(a>b){
        aux = a;
        a = b;
        b = aux;
    }
    for(int i = 1;i<a/2;i++){
        if(a%i == 0 && b%i == 0)
            r=i;
    }
    c = r;
}
void euclidesGeneralizado(int a,int b,int &MDC,int &x,int &y){
    if(b==0){
        MDC=a;
        x = 1;
        y = 0;
    }
    else{
        euclidesGeneralizado(b,a%b,MDC,x,y);
        int aux = x;
        aux = x;
        x = y;
        y = aux-(a/b)*y; 
    }
}

int main(){
    int a,b,mcd=0,x=0,y=0;
    cout<<"escriba el primer numero: ";
    cin >>a;cout<<"escriba el segundo numero : ";
    cin>>b;
    clock_t startTime = clock();
    euclides(a,b,mcd);
    
    // a*x +b*y = 1 
    //euclidesGeneralizado(a,b,mcd,x,y);
    cout<<"\nprimer numero: "<<a<<" segundo numero: "<<b<<" el MCD es: "<<mcd<<" x:"<<x<<" y:"<<y;
    cout <<"\n"<<double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    
    return 0;
}
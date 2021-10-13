#include "iostream"

using namespace std;
void imprimir(int *arr,int size){
    cout<<"arr: ";
    for(int *i=arr;i<arr+size;i++)
        cout<<*i<<", ";
    cout<<"\n";
}

void cockTail(int *Ini,int *Fin){
    int* inicio = Ini;int*final =Fin;
    int*o=inicio;o++;int aux = 0;
    for(int i=0;*final!=*inicio;i++){
        for(int *j= inicio;j<final;j++){
            if(*j<*o){o++;}
            else{
                aux = *o;
                *o=*j;
                *j=aux;
                o++;
            }
        }
        final--;o=final;o--;
        for(int *k = final;k>inicio;k--){
            if(*o<*k){o--;}
            else{
                aux=*k;
                *k = *o;
                *o=aux;
                o--;
            }
        }
        inicio++;o=inicio;o++;
    }
}
int main(){
    int l[10]={10,20,50,30,22,45,100,2,1,46};
    cout<<"sin ordenar\n";imprimir(l,10);
    cockTail(&l[0],&l[9]);
    cout<<"\nodernado\n";imprimir(l,10);
    return 0;
}
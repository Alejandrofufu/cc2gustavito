#include "iostream"
#include<cstdlib>
#include<ctime>
using namespace std;

void numrand(int *arr,int sizeI,int sizeJ){
    int *pt = arr;
    for(int i = 0;i<sizeI*sizeJ;i++){
        *pt = 1+rand()%15;pt++;
    }
}
srand(time(NULL));
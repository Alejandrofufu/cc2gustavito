// PointerMultiMatrix.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

void MultiMatrix(int(*A)[3], int(*B)[3], int(*C)[3])
{
    int* p = *A;
    int* q = *B;
    int* r = *C;

    while (p < *(A + 3)) // A+3 es el 4to renglon, no existe por lo que debe parar
    {
        if (r == *(C + 1)) //Si r se pasa el siguiente renglón
        {
            r = *C; //reseteo r
            p++; //y avanza p
        }
        if (q == *(B + 3)) // si q se sale de la matriz
        {
            q = *B; //q se resetea
            C++; //Bajamos de renglón
            r = *C; //r apunta al primer elemento en el nuevo renglón
        }

        if(p < *(A + 3)) //Para evitar multilpicar cuando ya nos hayamos salido de la matriz p 
            *r += *p * *q; //*r = *r + *p * *q;
        r++;
        q++;
    }
}

void MultiMatrix2(int(*A)[3][3])
{
    int* p = **(A+0);//int* p = *(*(A+0));
    int* q = **(A+1);//int* q = *(*(A+1));
    int* r = **(A+2); //int* r = *(*(A+2));
    int(*C)[3] = *(A + 2);

    while (p < *(*(A + 0) + 3)) // A+3 es el 4to renglon, no existe por lo que debe parar
    {
        if (r == *(C + 1)) //Si r se pasa el siguiente renglón
        {
            r = *C; //reseteo r
            p++; //y avanza p
        }
        if (q == *(*(A + 1) + 3)) // si q se sale de la matriz
        {
            q = **(A + 1); //q se resetea
            C++; //Bajamos de renglón
            r = *C; //r apunta al primer elemento en el nuevo renglón
        }

        if (p < *(*(A + 0) + 3)) //Para evitar multilpicar cuando ya nos hayamos salido de la matriz p 
            *r += *p * *q; //*r = *r + *p * *q;
        r++;
        q++;
    }
}

void Print(int(*A)[3])
{
    for (int(*p)[3] = A; p < A + 3; p++)
    {
        for (int* q = *p; q < *(p + 1); q++)
            cout << *q << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int ArrA[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    int ArrB[3][3] = { {11,12,13},{14,15,16},{17,18,19} };
    int ArrC[3][3] = { {0,0,0},{0,0,0},{0,0,0} };

    int ArrD[3][3][3] = { { {1,2,3},{4,5,6},{7,8,9} },
                          { {11,12,13},{14,15,16},{17,18,19} },
                          { {0,0,0},{0,0,0},{0,0,0} }
                        };

    cout << "Matriz A" << endl;
    Print(ArrA);
    cout << "Matriz B" << endl;
    Print(ArrB);
    MultiMatrix(ArrA, ArrB, ArrC);
    cout << "Matriz C" << endl;
    Print(ArrC);

    //-----------------------------------------
    cout << "Matriz D[0]" << endl;
    Print(*ArrD);
    cout << "Matriz D[1]" << endl;
    Print(*(ArrD+1));
    MultiMatrix2(ArrD);
    cout << "Matriz D[2]" << endl;
    Print(*(ArrD + 2));

}

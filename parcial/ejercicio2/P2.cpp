#include <iostream>

using namespace std;

char cipher(char Ent,int Key)
{
	return Ent*Key%256;
}

void procesa(char (*MatCad)[200], int MatTam, char (*Oper)(char,int),int key)
{
	for(char (*p)[200]=MatCad; p < MatCad+MatTam; p++){
		for(char *o=*p;o<*p+200;o++){
			*o=*o*key;
		}
	}
}

void imprimir(char (*MatCad)[200], int MatTam)
{
	for(char (*p)[200]=MatCad; p < MatCad+MatTam; p++)
		cout<<(p-MatCad)+1<<" - "<<*p<<endl;
}

int main() {
    char C[][200] = {"No hay caminos para la paz; la paz es el camino (Mahatma Gandhi)","Cada día sabemos más y entendemos menos (Albert Einstein)","El mundo no está en peligro por las malas personas sino por aquellas que permiten la maldad (Albert Einstein)"};
    int k[2] = {21, 61};

    cout<<"Frases sin encriptar"<<endl;
	imprimir(C,3);

	procesa(C,3,cipher,*k);
	cout<<endl<<"Frases encriptadas"<<endl;
	imprimir(C,3);

	procesa(C,3,cipher,*(k+1));
	cout<<endl<<"Frases desencriptadas"<<endl;
	imprimir(C,3);

	return 0;
}
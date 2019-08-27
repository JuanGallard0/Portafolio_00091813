#include<iostream>
#include<string.h>

using namespace std;

typedef struct pais
{
	string nombre;
	string capital;
	int habitantes;
	float mediaEdad;	
} pais;

int poblacionTotal(pais p[][5], int x)
{
	int result = 0; 
	for (int i = 0; i < 5; ++i)
	{
		result += p[x][i].habitantes;
	}
	return result;
}

float promedioEdadMundial(pais p[][5])
{
	float resultado = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			resultado += p[i][j].mediaEdad;
		}
	}
	return resultado / 25;
}

int main(void)
{
	pais Continente[5][5];
	for (int i = 0; i < 5; ++i)
	{
		switch (i)
			{
				case 0:
				cout<<"America: "<<endl;
				break;
				case 1:
				cout<<"Europa: "<<endl;
				break;
				case 2:
				cout<<"Asia: "<<endl;
				break;
				case 3:
				cout<<"Africa: "<<endl;
				break;
				case 4:
				cout<<"Oceania: "<<endl;
				break;

			}
		for (int j = 0; j < 5; ++j)
		{
			cout<<"Pais "<<j + 1<<endl;
			cout<<"Nombre: ";
			cin>>Continente[i][j].nombre;
			cout<<"Capital: ";
			cin>>Continente[i][j].capital;
			cout<<"Habitantes: ";
			cin>>Continente[i][j].habitantes;
			cout<<"Promedio de edad: ";
			cin>>Continente[i][j].mediaEdad;
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<endl<<endl<<"El numero de habitantes en America es: "<<poblacionTotal(Continente, 0)<<endl;
	cout<<endl<<endl<<"El promedio de edad mundial es: "<<promedioEdadMundial(Continente)<<endl<<endl;
	return 0;
}
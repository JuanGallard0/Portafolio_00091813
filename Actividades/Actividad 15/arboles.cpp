#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

struct nodo
{
	int dato;
	nodo* izq;
	nodo* der;
};
typedef struct nodo nodo;
typedef struct nodo* arbol;

arbol crearArbol(int x)
{
	arbol p = new nodo;
	p->dato = x;
	p->izq = nullptr;
	p->der = nullptr;
	return p;
}

void asignarIzq(arbol a, int x)
{
	if (!a)
		cout<<"Error, arbol vacio.\n";
	else if (a->izq)
		cout<<"Error: subarbol izq ya existe\n";
	else
		a->izq = crearArbol(x);
}

void asignarDer(arbol a, int x)
{
	if (!a)
		cout<<"Error, arbol vacio.\n";
	else if (a->der)
		cout<<"Error: subarbol izq ya existe\n";
	else
		a->der = crearArbol(x);
}

void agregarNodo(arbol a, int num)
{
	arbol p = a;
	while (true)
	{
		if (num == p->dato)
		{
			cout<<"El numero ya existe\n";
			return;
		}
		else if (num < p->dato)
		{
			if (p->izq == nullptr)
				break;
			else 
				p = p->izq;
		}
		else 
		{
			if (p->der == nullptr)
				break;
			else 
				p = p->der;
		}
	}
	if (num < p->dato)
		asignarIzq(p, num);
	else
		asignarDer(p, num);
}

int altura(arbol a)
{
	if (a == nullptr)
		return 0;
	else
	{
        int alturaIzq = altura(a->izq);  
        int alturaDer = altura(a->der);      
        if (alturaIzq > alturaDer)  
            return(alturaIzq + 1);  
        else return(alturaDer + 1);
	}
}

int main(void)
{
	srand(time(NULL));
	arbol a = crearArbol(0);
	int n;
	cout<<"n numeros que agregaremos al arbol: ";
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		agregarNodo(a, rand()%100+1);
	}
	cout<<"altura: "<<altura(a)<<endl;
	return 0;
}
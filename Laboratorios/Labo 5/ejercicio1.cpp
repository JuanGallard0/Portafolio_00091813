#include<iostream>

using namespace std;

typedef struct nodo
{
	int dato;
	nodo* izq;
	nodo* der;
}nodo;

nodo* crearNodo(nodo* T, int n)
{
	nodo* temp = new nodo;
	temp->dato = n;
	temp->izq = nullptr;
	temp->der = nullptr;
	return temp;
}

nodo* insertar(nodo* T, int n)
{
	if (!T)
		return crearNodo(T, n);
	if (n < T->dato)
		T->izq = insertar(T->izq, n);
	else 
		T->der = insertar(T->der, n);
	return T;
}

void in_order(nodo* T)
{
	if (!T)
		return;
	in_order(T->izq);
	cout<<T->dato<<endl;
	in_order(T->der);
}

int altura(nodo* T)
{
	if (!T)
		return -1;
	{
		int l = altura(T->izq);
		int r = altura(T->der);
		if (l > r)  
		    return(l + 1);  
    	else 
    		return(r + 1);
    }
}

int cantidadNodos(nodo* T)
{
	if (!T)
		return 0;
	return cantidadNodos(T->izq) + cantidadNodos(T->der) + 1;
}

int sumaNodos(nodo* T)
{
	if (!T)
		return 0;
	return sumaNodos(T->izq) + sumaNodos(T->der) + T->dato;
}

int main(void)
{
	nodo* T = nullptr;
	T = insertar(T, 8);
	T = insertar(T, 10);
	T = insertar(T, 13);
	T = insertar(T, 3);
	T = insertar(T, 4);
	T = insertar(T, 6);
	T = insertar(T, 7);
	T = insertar(T, 14);
	T = insertar(T, 1);
	cout<<"La altura del arbol es: "<<altura(T)<<endl;
	cout<<"La cantidad de nodos es: "<<cantidadNodos(T)<<endl;
	cout<<"La suma de nodos es: "<<sumaNodos(T)<<endl;
	return 0;
}
#include<iostream>
#include<vector>
#include<time.h>

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
	if (!T or T->dato == n)
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
	cout<<T->dato<<"->";
	in_order(T->der);
}

nodo* valorMinimo(nodo* T) 
{ 
    nodo* temp = T; 
    while (temp and temp->izq) 
        temp = temp->izq; 
    return temp; 
} 

void listaEnArbol(nodo*& T, vector<int>& l)
{
	for (int i = 0; i < l.size(); ++i)
	{
		T = insertar(T, l.at(i));
	}
}

int main(void)
{
	int x;
	srand(time(NULL));
	nodo* T = nullptr;
	vector<int> lista;
	cout<<"Lista: ";
	for (int i = 0; i < 20; ++i)
	{
		x = rand() % 20 + 1;
		lista.push_back(x);
		cout<<lista.at(i)<<", ";
	}
	listaEnArbol(T, lista);
	cout<<endl<<"Arbol in-order: ";
	in_order(T);
	return 0;
}
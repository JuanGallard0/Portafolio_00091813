#include<iostream>
#include<vector>

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
	cout<<T->dato<<endl;
	in_order(T->der);
}

nodo* valorMinimo(nodo* T) 
{ 
    nodo* temp = T; 
    while (temp and temp->izq) 
        temp = temp->izq; 
    return temp; 
} 

void rutaBusqueda(nodo* T, vector<int>& l, int n)
{
	if (!T)
	{
		l.erase(l.begin(), l.end());
		return;
	}
	if (T->dato == n)
	{
		l.push_back(T->dato);
		return;
	}
	else if (n < T->dato)
	{
		l.push_back(T->dato);
		rutaBusqueda(T->izq, l, n);
	}
	else
	{ 
		l.push_back(T->dato);
		rutaBusqueda(T->der, l, n);
	}
}

int main(void)
{
	nodo* T = nullptr;
	std::vector<int> lista;
	T = insertar(T, 8);
	T = insertar(T, 10);
	T = insertar(T, 13);
	T = insertar(T, 3);
	T = insertar(T, 4);
	T = insertar(T, 6);
	T = insertar(T, 7);
	T = insertar(T, 14);
	T = insertar(T, 1);
	rutaBusqueda(T, lista, 14);
	cout<<"Ruta de busqueda: ";
	for (int i = 0; i < lista.size(); ++i)
	{
		cout<<lista.at(i)<<"->";
	}
	cout<<endl;
	return 0;
}
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

int cantidadPares(nodo* T)
{
  if (!T)
    return 0;
  int temp = cantidadPares(T->izq) + cantidadPares(T->der);
  if (T->dato % 2 == 0)
    return temp + 1;
  else
    return temp;
}

int cantidadImpares(nodo* T)
{
  if (!T)
    return 0;
  int temp = cantidadImpares(T->izq) + cantidadImpares(T->der);
  if (T->dato % 2 != 0)
    return temp + 1;
  else
    return temp;
}

int sumaPares(nodo* T)
{
  if (!T)
    return 0;
  int temp = sumaPares(T->izq) + sumaPares(T->der);
  if (T->dato % 2 == 0)
    return temp + T->dato;
  else
    return temp;
}

int sumaImpares(nodo* T)
{
  if (!T)
    return 0;
  int temp = sumaImpares(T->izq) + sumaImpares(T->der);
  if (T->dato % 2 != 0)
    return temp + T->dato;
  else
    return temp;
}

int cantidadNegativos(nodo* T)
{
  if (!T)
    return 0;
  int temp = cantidadNegativos(T->izq) + cantidadNegativos(T->der);
  if (T->dato < 0)
    return temp + 1;
  else
    return temp;
}

int cantidadPositivos(nodo* T)
{
  if (!T)
    return 0;
  int temp = cantidadPositivos(T->izq) + cantidadPositivos(T->der);
  if (T->dato > 0)
    return temp + 1;
  else
    return temp;
}

int cantidadZeros(nodo* T)
{
  if (!T)
    return 0;
  int temp = cantidadZeros(T->izq) + cantidadZeros(T->der);
  if (T->dato == 0)
    return temp + 1;
  else
    return temp;
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
  cout<<"La cantidad de pares es: "<<cantidadPares(T)<<endl;
  cout<<"La cantidad de impares es: "<<cantidadImpares(T)<<endl;
  cout<<"La suma de pares es: "<<sumaPares(T)<<endl;
  cout<<"La suma de impares es: "<<sumaImpares(T)<<endl;
  cout<<"La cantidad de negativos es: "<<cantidadNegativos(T)<<endl;
  cout<<"La cantidad de positivos es: "<<cantidadPositivos(T)<<endl;
  cout<<"La cantidad de zeros es: "<<cantidadZeros(T)<<endl;
	return 0;
}

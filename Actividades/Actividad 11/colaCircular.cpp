#include<iostream>

using namespace std;

typedef struct Nodo
{
	float elemento;
	Nodo* siguiente;
}Nodo;

typedef struct Cola
{
	Nodo* frente;
	Nodo* final;
}Cola;

bool empty(Cola* q)
{
	return (q->frente == NULL);
}

void insert(Cola* q, float x)
{
	Nodo* unNodo = new Nodo;
	unNodo->elemento = x;
	if (q->frente == NULL)
		q->frente = unNodo;
	else 
		q->final->siguiente = unNodo;
}

float remove(Cola* q)
{
	if (empty(q))
	{
		cout<<"Underflow!"<<endl;
		return -1;
	}
	float x;
	if (q->frente == q->final)
	{
		x = q->frente->elemento;
		q->frente = NULL;
		q->final = NULL;
		delete(q->frente);
	}
	else
	{
		Nodo* unNodo = q->frente;
		x = unNodo->elemento;
		q->frente = q->frente->siguiente;
		q->final->siguiente = q->frente;
		delete(unNodo);
	}
}

int main(void)
{
	
	return 0;
}
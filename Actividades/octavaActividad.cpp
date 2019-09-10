#include<iostream>

using namespace std;

struct Tpila
{
	float elements[100];
	int top;
};
typedef struct Tpila Pila;

void initialize(Pila *s)
{
	s->top = -1;
}

bool empty(Pila *s)
{
	return s->top < 0;
}

void push(Pila *s, float e)
{
	if (s->top < 99)
	{
		(s->top)++;
		s->elements[s->top] = e;
	}
}

float pop(Pila *s)
{
	if (s->top >= 0)
	{
		(s->top)--;
		return s->elements[s->top + 1];
	}
	else
		return -1;
}

float peek(Pila *s)
{
	if (s->top >= 0)
	{
		return s->elements[s->top];
	}
	else
		return -1;
}

void mostrarPila(Pila *s)
{
	int temp = s->top;
	if (empty(s))
		cout<<"Pila vacia."<<endl;
	else
	{
		while (temp >= 0)
		{
			cout<<s->elements[temp]<<", ";
			temp--;
		}
		cout<<endl;
	}
}

float ultimoElementoVaciar(Pila *s)
{
	float lastElement = 0;
	while (!empty(s))
	{
		lastElement = pop(s);
	}
	return lastElement;
}

float ultimoElemento(Pila *s)
{
	int temp = s->top;
	if (empty(s))
	{
		cout<<"Pila vacia."<<endl;
		return -1;
	}	
	else
	{
		while (temp > 0)
		{
			temp--;
		}
		return s->elements[temp];
	};
}

int main(void)
{
	Pila stack; Pila tempStack;
	initialize(&stack);
	initialize(&tempStack);
	for (int i = 1; i <= 10; ++i)
	{
		push(&stack, i);
		push(&tempStack, i);
	}
	cout<<"Pila inicial: ";
	mostrarPila(&stack);
	cout<<endl<<"El elemento al fondo de la pila es: "<<ultimoElementoVaciar(&stack)<<endl;
	cout<<"Pila luego de llamar la funcion: ";
	mostrarPila(&stack);
	cout<<endl<<"El elemento al fondo de la pila es: "<<ultimoElemento(&tempStack)<<endl;
	cout<<"Pila luego de llamar la funcion: ";
	mostrarPila(&tempStack);
	cout<<endl;
	return 0;
}
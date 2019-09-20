#include<iostream>
#include<string>
#include<stack>

using namespace std;

typedef struct id
{
	int edad;
	char sexo;
	string nombre;
}id;

id ultimoElemento(stack<id> s)
{
	id res;
	while(!s.empty())
	{
		res = s.top();
		s.pop();
	}
	return res;
}

int main(void)
{
	int N;
	stack<id> s; 
	cout<<"Ingrese numero de personas: ";
	cin>>N;
	cout<<endl;
	id A[N];
	for (int i = 0; i < N; ++i)
	{
		cout<<"Sujeto "<<i + 1<<": ";
		cin>>A[i].edad>>A[i].sexo>>A[i].nombre;
		s.push(A[i]);
	}
	id ultimo = ultimoElemento(s);
	cout<<endl<<"Ultimo elemento de la pila: "<<endl;
	cout<<"edad: "<<ultimo.edad<<endl<<"sexo: "<<ultimo.sexo<<endl<<"nombre: "<<ultimo.nombre<<endl;
	return 0;
}
#include<iostream>

using namespace std;

typedef struct libro
{
	string titulo;
	int numPaginas;
	libro* sig;
}libro;

libro* inicio = nullptr;

libro* crearLibro(string t, int n)
{
	libro* l = new libro;
	l->titulo = t;
	l->numPaginas = n;
	l->sig = nullptr;
	return l;
}

void agregarLibro(libro* l, string t, int n)
{
	l = crearLibro(t, n);
	libro* temp;
	if (!inicio)
		inicio = l;
	else 
	{
		for (temp = inicio; temp->sig; temp = temp->sig);
		temp->sig = l;
	}
}

void paginas(libro* l, string t, int &p)
{
	if (l)
	{
		if (l->titulo == t)
		{
			p = l->numPaginas;
			paginas(l->sig, t, p);
		}
		else 
			paginas(l->sig, t, p);
	} 
}

int main(void)
{
	libro* l; int p = -1;
	agregarLibro(l, "dracula", 200);
	agregarLibro(l, "comedy", 233);
	agregarLibro(l, "iliade", 500);
	agregarLibro(l, "potter", 144);
	agregarLibro(l, "principito", 307);
	paginas(inicio, "iliade", p);
	cout<<"Numero de paginas en el libro: "<<p<<endl;
	return 0;
}

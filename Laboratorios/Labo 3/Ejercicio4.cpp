#include<iostream>

using namespace std;

struct nodo
{
  int data;
  nodo* next;
}*inicio;

class listaEnlazada
{
public:

  listaEnlazada()
  {
    inicio = nullptr;
  }

  nodo* getIni()
  {
    return inicio;
  }

  nodo* crearNodo(int valor)
  {
    nodo* n = new nodo;
    n->data = valor;
    n->next = nullptr;
    return n;
  }

  void agregarElemento(int valor)
  {
    nodo* n = crearNodo(valor), *temp;
    if (!inicio)
      inicio = n;
    else
    {
      for (temp = inicio; temp->next; temp = temp->next);
      temp->next = n;
    }
  }

  void mostrarLista()
  {
    nodo* temp = inicio;
    if (!inicio)
      cout<<"No hay elementos en la lista."<<endl;
    else
    {
      while (temp)
      {
        cout<<temp->data<<", ";
        temp = temp->next;
      }
    }
  }
};

void sumaParImpar(nodo* temp ,int& a, int& b, int n)
{
  if (n > 0)
  {
    if (temp->data % 2 == 0)
    {
      a += temp->data;
      temp = temp->next;
      sumaParImpar(temp, a, b, n-1);
    }
    else
    {
      b += temp->data;
      temp = temp->next;
      sumaParImpar(temp, a, b, n-1);
    }
  }
}

int main()
{
  listaEnlazada l;
  int n = 20;
  for (int i = 0; i < n; i++)
  {
    l.agregarElemento(i);
  }
  l.mostrarLista();
  int sumaPar = 0, sumaImpar = 0;
  sumaParImpar(l.getIni() ,sumaPar, sumaImpar, n);
  cout<<endl<<"Suma par: "<<sumaPar<<"\t Suma impar: "<<sumaImpar<<endl;
  return 0;
}

#include<iostream>

using namespace std;

void imprimirLista(int a, int b)
{
  if (a <= b)
  {
      cout<<a<<", ";
      imprimirLista(a + 1, b);
  }
}

int main(void)
{
  int a, b;
  cout<<"a: ";
  cin>>a;
  cout<<"b: ";
  cin>>b;
  cout<<endl<<"Lista: ";
  imprimirLista(a, b);
  return 0;
}

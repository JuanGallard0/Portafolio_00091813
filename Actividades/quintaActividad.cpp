#include<iostream>

using namespace std;

int multiplicacion(int a, int b)
{
	if (b > 1)
	{
		return a + multiplicacion(a, b - 1);
	}
	return a;
}

int main(void)
{
	int a, b;
	cout<<"a: ";
	cin>>a;
	cout<<endl<<"b: ";
	cin>>b;
	cout<<endl<<"a * b= "<<multiplicacion(a, b)<<endl;
	return 0;
}
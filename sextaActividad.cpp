#include<iostream>

using namespace std;

int binarySearch(int *a, int low, int high, int x)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (x == a[mid])
		return mid;
	if (x < a[mid])
		return binarySearch(a, low, mid - 1, x);
	else
		return binarySearch(a, mid + 1, high, x);
}

int main(void)
{
	int a[] = {1, 3, 4, 5, 17, 18, 31, 33};
	int n;
	cout<<"Ingrese numero entero positivo: ";
	cin>>n;
	int i = binarySearch(a, 0, 7, n);
	if (i == -1)
		cout<<endl<<n<<" no esta en el arreglo."<<endl;
	else
		cout<<endl<<n<<" se encuentra en el indice "<<i<<" del arreglo."<<endl;
	return 0;
}
#include<iostream>

using namespace std;

int maxSearch(int *A, int n)
{
    int temp = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > temp)
            temp = A[i];
    }
    return temp;
}
int main(void)
{
    int A[] = {4, 97, 56, 14, 23, 45, 7, 33, 25, 66};
    cout<<"El mayor numero en el arreglo es "<<maxSearch(A, 10)<<"."<<endl;
    return 0;
}
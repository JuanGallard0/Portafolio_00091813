#include<iostream>
#include<math.h>

using namespace std;

void merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], R[n2];
	for (int i = 0; i < n1; ++i)
	{
		L[i] = A[p + i];
	}
	for (int j = 0; j < n2; ++j)
	{
		R[j] = A[q + 1 + j];
	}
	int i = 0; int j = 0;
	for (int k = p; k <= r; ++k)
	{
		if (i == n1)
			A[k] = R[j++];
		else if (j == n2)
			A[k] = L[i++];
		else if (L[i] <= R[j])
			A[k] = L[i++];
		else 
			A[k] = R[j++];
	}
}

void mergeSort(int A[], int p, int r)
{
  if (p < r)
  {
  	int q = floor((p + r) / 2);
  	mergeSort(A, p, q);
  	mergeSort(A, q + 1, r);
  	merge(A, p, q, r);
  }
}

int main(void)
{
  int A[] = {85,47,63,25,11,24,68,95,36,55};
  mergeSort(A, 0, 9);
  for (int i = 0; i < 10; ++i)
  {
  	cout<<A[i]<<", ";
  }
  cout<<endl;
  return 0;
}

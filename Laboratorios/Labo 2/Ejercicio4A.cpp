#include<iostream>
#include<math.h>

using namespace std;

float pi(int n)
{
  if (n > 0)
  {
    return pi(n - 1) + 4 * pow(-1, n) / (2 * n + 1);
  }
  else
    return 4;
}

int main(void)
{
  int n= 0;
  cout<<"n: ";
  cin>>n;
  cout<<endl<<"pi despues de "<<n<<" iteraciones: "<<pi(n)<<endl;
  return 0;
}

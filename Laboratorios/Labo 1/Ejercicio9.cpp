#include<iostream>
#include<math.h>

using namespace std;

int potenciacion(int x, int n)
{
    if (n == 0) 
        return 1;
    else if (n == 1)
        return x;
    else 
        return pow(x, n) + potenciacion(x, n - 1);
}

int main(void)
{
    int x, n;
    cout<<"Ingrese x:";
    cin>>x;
    cout<<"Ingrese n:";
    cin>>n;
    cout<<endl;
    cout<<"Resultado sumatoria de potencias: "<<potenciacion(x, n)<<endl;
}
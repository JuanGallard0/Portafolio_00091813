#include<iostream>
#include<math.h>

using namespace std;

typedef struct complejo
{
    int re; 
    int im;

    complejo(){}
    complejo(int r, int i)
    {
        re = r;
        im = i;
    }
} complejo;

float valorAbsoluto(complejo z)
{
    return sqrt(pow(z.re, 2) + pow(z.im, 2));
}

int main(void)
{
    complejo z(4, 7);
    cout<<"Valor absoluto: "<<valorAbsoluto(z)<<endl;
    return 0;
}
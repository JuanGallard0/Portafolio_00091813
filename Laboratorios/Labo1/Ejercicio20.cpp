#include<iostream>

using namespace std;

int main(void)
{
    int M[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i >= j)
                M[i][j] = 0;
            else
                {
                    cout<<"["<<i + 1<<"]"<<"["<<j + 1<<"]: ";
                    cin>>M[i][j];
                }
        }
    }
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<"["<<M[i][j]<<"]";
        }
        cout<<endl;
    }
}
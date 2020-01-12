#include <iostream>
#include <iomanip>
#include "const.h"

using namespace std;

void ghigiatri(const int &,const int &,const int &);//ghi gia tri
void maphuong(const int &);//tao ma phuong
void out(const int &);// xuat data

int MP[MAX][MAX] = {0};

int main()
{
    int *N = new int;
    cout << "N = ";
    cin >> *N;
    maphuong(*N);
    out(*N);
    return 0;
}

void ghigiatri(const int &i,const int &j,const int &n)
{
    MP[i][j] = n;
}

void maphuong(const int &N)
{
    int i, j, n, k;
    n = 1;
    k = N / 2;
    i = k + 1;
    j = k;
    while (n <= N * N)
    {
        if (i == N)
            i = 0;
        if (i >= N)
            i = 1;        
        if (j < 0)
            j = N - 1;
        if (MP[i][j] == 0)
        {

            ghigiatri(i, j, n);
            n++;
        }
        if ((n - 1) % N == 0)
        {
            i += 2;
        }
        else
        {
            i++;
            j--;
        }
    }
}

void out(const int &N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "|" << setw(2) << MP[j][i] << "|";
        }
        cout << endl;
    }
}
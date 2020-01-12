#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const int MAX = 100;
const int MAXluong = 50;

int Apt[MAX] = {1,4,3,2};
int Bpt[MAX] = {0};
int B[MAXluong] = {0};
int n = 4;
bool Bool[MAX] = {false};
int dem = 0;

void in();
void out();
void hoanvi(int);
void gethoanvi();
bool checkphantu();
void checkmin();
void tachphantu(int);

int main()
{
    //in();
    hoanvi(0);
    checkmin();
    out();
    cout << "xong!" << endl;
}

void in()
{
    ifstream infile;
    infile.open("minperin.IN");
    infile >> n;
    for (int i = 0; i < n; i++)
    {
        infile >> Apt[i];
    }
    infile.close();
}

void out()
{
    ofstream outfile;
    outfile.open("minper.txt");
    for (int i = 0; i < n; i++)
    {
        outfile << Bpt[i];
    }
    outfile.close();
}

void hoanvi(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (Bool[i] == false)
        {
            Bool[i] = true;
            Bpt[k] = i;
            if (k == n - 1)
            {
                gethoanvi();
            }
            else
            {

                hoanvi(k + 1);
            }
            Bool[i] = false;
        }
    }
}

void gethoanvi()
{
    if (checkphantu())
    {
        for (int i = n; i >= 0; i--)
        {
            B[dem] = Bpt[i] * pow(10, i);
            dem++;
        }
    }
}

bool checkphantu()
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (Bpt[i] >= Apt[i] -1 && Bpt[i] <= Apt[i] + 1)
            check = 1;
        else
            return false;
    }
    if (check == 1)
    return true;    
}

void checkmin()
{
    int min = B[0];
    int i = 0;
    for (int i = 1; i < dem; i++)
    {
        if (min > B[i])
        {
            min = B[i];
        }
    }
    tachphantu(min);
}

void tachphantu(int M)
{
    for (int i = 0; i < n; i++)
    {
        Bpt[n - i] = M % 10;
        M /= 10;
    }
}
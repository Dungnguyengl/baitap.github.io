#include <fstream>
#include <iostream>
#include <math.h>
#include <array>
#include "const.h"

using namespace std;

class General
{
private:
    std::ifstream infile;
    std::ofstream outfile;

    int Y[MAXluong] = {0};
    int n, k;
    bool Bool[MAXgt] = {false};
    int dem = 1;

public:
    General();
    void hoanvi(int, array<int, MAXgt> &);
    void gethoanvi(const array<int, MAXgt> &);
    bool kiemtra(int *);
    bool sosanh(const int &, const int &);
    void out();
};

General::General()
{
    infile.open("hoanvi.bat");
    infile >> n;
    infile >> k;
    infile >> Y[0];
    infile.close();
    outfile.open("hoanvi.txt");
    outfile.clear();
    outfile.close();
}

void General::hoanvi(int iPhantu, array<int, MAXgt> &tempY)
{
    for (int i = 1; i <= n; i++)
    {
        if (Bool[i] == false)
        {
            Bool[i] = true;
            tempY.at(iPhantu) = i;
            if (iPhantu == n - 1)
                gethoanvi(tempY);
            else
            {
                hoanvi(iPhantu + 1, tempY);
            }
            Bool[i] = false;
        }
    }
}

void General::gethoanvi(const array<int, MAXgt> &tempY)
{
    int *cache = new int;
    *cache = 0;
    for (size_t i = 0; i < n; i++)
    {
        *cache += tempY.at(i);
        *cache *= 10;
    }
    *cache /= 10;

    if (kiemtra(cache) == true)
    {
        Y[dem] = *cache;
        dem++;
    }
    delete cache;
}

bool General::kiemtra(int *cY)
{
    if (*cY > Y[0])
    {
        delete cY;
        return true;
    }
    else
    {
        delete cY;
        return false;
    }
}

bool General::sosanh(const int &Y, const int &k)
{
    if (Y % k == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void General::out()
{
    outfile.open("hoanvi.txt");
    for (int i = 1; i < dem; i++)
    {
        if (sosanh(Y[i], k) == true)
        {
            outfile << Y[i];
        }
    }
}

int main()
{
    General general;
    array<int, MAXgt> arr = {0};
    general.hoanvi(0, arr);
    general.out();
    return 0;
}
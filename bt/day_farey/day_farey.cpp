#include <fstream>
#include <iostream>

using namespace std;

void in();
void out();
void Farey();
void arrageFarey();
void getFarey(int, int);
bool rutgon(int, int);
int UCLN(int, int);

const int MAX = 300;

struct Fraction
{
    int tu;
    float mau;
};

int n, t, m;
int k = 1;
Fraction fraction[MAX];

int main()
{
    fraction[0].tu = 0;
    fraction[0].mau = 1;
    in();
    Farey();
    arrageFarey();
    out();
    cout << "XONG!" << endl;
    return 0;
}

//nhap du lieu
void in()
{
    ifstream infile;
    infile.open("farey.bat");
    infile >> n;
    infile.close();
}

//xuat du lieu
void out()
{
    ofstream outfile;
    outfile.open("farey.txt");
    outfile << k << endl;
    for (int i = 0; i < k; i++)
    {
        outfile << fraction[i].tu << " " << fraction[i].mau << endl;
    }
    outfile.close();
}

// tim UCLN
int UCLN(int x, int y)
{
    while (x != y && x != 0 && y != 0)
    {
        if (x > y)
        {
            x = x - y;
        }
        else
        {
            y = y - x;
        }
    }
    if (x == 0 || y == 0)
    {
        return 1;
    }
    return x;
}

//kiem tra rut gon
bool rutgon(int t, int m)
{
    if (UCLN(t, m) == 1)
        return true;
    else
        return false;
}

//tao Farey
void Farey()
{
    for (int m = 1; m <= n; m++)
    {
        for (int t = 1; t <= m; t++)
        {
            if (rutgon(t, m))
            {
                getFarey(t, m);
                k++;
            }
        }
    }
}

//nhap Farey vao mang;
void getFarey(int gt, int gm)
{
    fraction[k].tu = gt;
    fraction[k].mau = gm;
}

//sap xep Farey
void arrageFarey()
{
    double f[MAX] = {0};
    Fraction clipboard;
    for (int i = 0; i < k; i++)
    {
        f[i] = fraction[i].tu / fraction[i].mau;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (f[i] < f[j])
            {
                //f
                f[i] = f[i] + f[j];
                f[j] = f[i] - f[j];
                f[i] = f[i] - f[j];
                //fraction
                clipboard = fraction[i];
                fraction[i] = fraction[j];
                fraction[j] = clipboard;
            }
        }
    }
}

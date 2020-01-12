#include <iostream>
#include <random>

using namespace std;

int lacxucxac()
{
    random_device xucxac;
    mt19937 xucxacng(xucxac());
    uniform_int_distribution<int> xucxacuni(1, 6);
    return xucxacuni(xucxacng);
}

int main()
{
    int xucxac[3];
    int tongdiem;
    char chon;
    cout << "tai hay xiu: (T/X)" << endl;
    cin >> chon;
    for (int i = 0; i < 3; i++)
    {
        xucxac[i] = lacxucxac();
    }
    if (xucxac[0] == xucxac[1] && xucxac[1] == xucxac[2])
    {
        cout << "[" << xucxac[0] << "];[" << xucxac[1] << "];[" << xucxac[2] << "]" << endl;
        cout << "Bo ba dong nhat!" << endl;
        cout << "Ban thua!";
    }
    else
    {
        tongdiem = xucxac[0] + xucxac[1] + xucxac[2];
    }
    if (tongdiem >= 4 && tongdiem <= 10)
    {
        cout << "[" << xucxac[0] << "];[" << xucxac[1] << "];[" << xucxac[2] << "] ";
        cout << "xiu" << endl;
        if (chon == 'X' || chon == 'x')
        {
            cout << "ban thang!" << endl;
        }
        else
        {
            cout << "ban thua!" << endl;
        }
    }
    if (tongdiem >= 11 && tongdiem <= 17)
    {
        cout << "[" << xucxac[0] << "];[" << xucxac[1] << "];[" << xucxac[2] << "] ";
        cout << "tai" << endl;
        if (chon == 't' || chon == 'T')
        {
            cout << "ban thang!" << endl;
        }
        else
        {
            cout << "ban thua!" << endl;
        }
    }
    return 0;
}
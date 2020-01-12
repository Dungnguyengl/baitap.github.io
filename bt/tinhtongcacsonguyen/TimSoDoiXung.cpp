#include<iostream>

int TimSoDoiXung(int);
bool Sosanh(int);

int main()
{
    int nSoNguyen;
    std::cout << "nhap so nguyen: ";
    std::cin >> nSoNguyen;
    if (Sosanh(nSoNguyen))
    {
        std::cout << "La so doi xung!" << std::endl;
    }
    else 
    {
        std::cout << "Khong la so doi xung!" << std::endl;
    }
    return 0;
}

int TimSoDoiXung(int nSoNguyen)
{
    int nSoDoiXung = 0 , nCache;
    while (nSoNguyen != 0)
    {
        nCache = nSoNguyen % 10;
        nSoDoiXung = (nSoDoiXung * 10) +nCache;
        nSoNguyen = nSoNguyen / 10;
    }
    return nSoDoiXung;
}

bool Sosanh(int nSoNguyen)
{
    return (nSoNguyen == TimSoDoiXung(nSoNguyen));
}
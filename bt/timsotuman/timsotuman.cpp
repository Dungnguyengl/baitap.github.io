#include <iostream>

int tim_so_nguyen_duong(int);
int tach_so(int);
int tong(int, int);
bool sosanh(int);

int main()
{
    int nInput;
    std::cout << "nhap so:";
    std::cin >> nInput;
    if (sosanh(nInput))
    {
        std::cout << "la so tu man " << tim_so_nguyen_duong(nInput) << " chu so!" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    return 0;
}

int tim_so_nguyen_duong(int nso)
{
    if (nso <= 10)
    {
        return 1;
    }
    return 1 + tim_so_nguyen_duong(nso / 10);
}

int tach_so(int nInput)
{
    return nInput % 10;
}

int tong(int nInput, int nSoChuSo)
{
    if (nInput == 0)
    {
        return 0;
    }
    int nSum = 1;
    for (int i = 0; i < nSoChuSo; i++)
    {
        nSum = nSum * tach_so(nInput);
    }
    return nSum + tong(nInput / 10, nSoChuSo);
}

bool sosanh(int nInput)
{
    return (nInput == tong(nInput, tim_so_nguyen_duong(nInput)));
}
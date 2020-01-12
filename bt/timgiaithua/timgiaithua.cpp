#include <iostream>

int tim_giai_thua(int);

int main()
{
    int nso;
    std::cout << "nhap so: ";
    std::cin >> nso;
    std::cout << "giai thua cua " << nso << " la: " << tim_giai_thua(nso) << std::endl;
    return 0;
}

int tim_giai_thua(int nso)
{
    if (nso == 0)
    {
        return 1;
    }

    return nso * tim_giai_thua(nso - 1);
}
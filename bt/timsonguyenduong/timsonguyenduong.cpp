#include<iostream>

int tim_so_nguyen_duong(int);

int main()
{
    int nso_ban_dau;
    std::cout << "nhap so:" ;
    std::cin >> nso_ban_dau;
    std::cout << "so nguyen duong co la:" << tim_so_nguyen_duong(nso_ban_dau) << std::endl;
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
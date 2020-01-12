#include<iostream>
#include<random>

using namespace std;

int Chon(char chon)
{
    switch (chon)
    {
    case 'b':
        return 1;
        break;
    case 'c':
        return 2;
        break;
    case 't':
        return 3;
        break;
    }
}

int main()
{
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1,3);
    do
    {
        auto n = uni(rng);
    cout << "vui long chon Bau/Cua/Tom! (B/C/T)" << endl;
    char chon;
    cin >> chon;

    if (Chon(chon) != n)
    {
        cout << "ban sai!" << endl;
    }
    else
    {
        cout << "ban dung!" << endl;
    }
    
    
    } while (true);
    
    
}
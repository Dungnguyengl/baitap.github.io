#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

const int MS = 1000000;

int ran()
{
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(0,1);
    return uni(rng);
}

void draw(int column, int n)
{
    int row = (((column + n) * 2) - 1);
    for (int i = 0; i < n; i++)
    {
        for (int i = 1; i <= column; i++)
        {
            int temp = ((row - ((i * 2) - 3))*3) / 2;
            cout << setw(temp);
            for (int j = 0; j < ((i * 2) - 1); j++)
            {
                if(ran() && j != 0 && j != ((i * 2) - 2))
                cout << "<c>";
                else
                cout << "<*>";
            }
            cout << endl;
            usleep(0.5 * MS);
        }
        column++;
    }
}

int main()
{
    draw(5, 3);
    return 0;
}
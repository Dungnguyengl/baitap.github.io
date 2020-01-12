#include <iostream>

using namespace std;

const int MAX = 2009;
const int CHUAN = 612;

bool So[MAX] = {false};
int dem = MAX;

int check(int);

int main()
{
    int L;
    int tam = check(0);
    // cau a
    cout << "so con lai la: " << tam << endl;
    //cau b
    cout << "nhap L (0<L<=2009)" << endl;
    cin >> L;
    if (L >= tam)
    {
        cout << "so bat dau la: " << L - tam + 1 << endl;
    }
    else
    {
        cout << "so bat dau la: " << L + (MAX - (tam - 1)) << endl;
    }
    
    return 0;
}

int check(int f)
{
    int i = 0;
    
    while (i < MAX && dem != 1)
    {

        if (So[i] == false)
        {

                if (f == CHUAN)
                {
                    So[i] = true;
                    dem--;
                    f = 0;
                }
            f++;
            
        }
        i++;
    }
    if (dem == 1)
    {
        for (int i = 0; i < MAX; i++)
        {
            if (So[i] == false)
            {
                return i + 1;
            }
        }
    }
    else
    {
        check(f);
    }
}
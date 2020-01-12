#include <iostream>

using namespace std;

struct Connect
{
    int webdi;
    int webden;
} connect[10];

bool Bool[10] = {false};
int finish, start, Min = 100;
int Lt[10];
int vitri = 0;
int m,n;

void in();
void lotrinh(int, int);
void getlotrinh(int);
int check(int);

int main()
{
    int dem = 0;
    int ch[10];
    in();
    for (int i = 1; i <= n; i++)
    {
        finish = i;
        lotrinh(start,0);
        ch[i]=check(vitri);
        Min = 100;
    }
    for (int i = 1; i < n; i++)
    {
        if (ch[i] >= 2)
            dem ++;   
    }
    cout << dem << endl;
    return 0;
}

void in()
{
    cout << "diem dau =";
    cin >> start;
    cout << "m=";
    cin >> m;
    cout << "n";
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        cout << "web di: ";
        cin >> connect[i].webdi;
        cout << "web den: ";
        cin >> connect[i].webden;
    }
    
}

void lotrinh(int in, int dem)
{
    Bool[in] = true;
    for (int i = 0; i < m; i++)
        if (connect[i].webdi == in)
            if (!Bool[connect[i].webden])
                if (connect[i].webden == finish)
                    getlotrinh(dem+1);
                else
                    lotrinh(connect[i].webden, dem + 1);
    Bool[in] = false;
}

void getlotrinh(int dem)
{
    int k = 1;
    if (dem == Min)
    {
        Lt[vitri + 1] = dem;
        vitri++;
    }
    if (dem < Min)
    {
        for (int i =0; i < vitri; i++)
            Lt[i] = 0;
        Min = dem;
        Lt[vitri] = dem;
    }    
    
    
}

int check(int dem)
{
    int n=0;
    for (int i = 0; i <= dem; i++)
    {
        if (Lt[i]!=0)
            n++;
    }
    return n;
}
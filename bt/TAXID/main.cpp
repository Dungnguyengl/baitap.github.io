#include <string.h>
#include <iostream>
#include <string>
#include <stack>
#include <array>

using namespace std;

struct TAX
{
    int cuc;
    string ID;
} tax[100];

int n, k, m, p, q;

void in(array<int, 30> &);               //nhap
string search36(const int &);            //search ki tu dang 36
void initialization();                   //tao id
void divide(const array<int, 30> &);     //chia cuc
string search(const int &, const int &); //tim id

stack<string> st;

int main()
{
    array<int, 30> c = {0};
    string *pid;
    in(c);
    initialization();
    divide(c);
    *pid = search(q, p);
    cout << *pid << endl;
    delete pid;
}

void in(array<int, 30> &c)
{
    cout << "n= ";
    cin >> n;
    cout << "m =";
    cin >> m;
    cout << "p =";
    cin >> p;
    cout << "q =";
    cin >> q;
    k = (m - 1) / 2;
    for (int i = 0; i < k; i++)
    {
        cout << "c " << i + 1 << "=";
        cin >> c[i];
    }
}

string search36(const int &temp)
{
    if (temp <= 9)
        return to_string(temp);
    else
        switch (temp)
        {
        case 10:
            return "a";
            break;
        case 11:
            return "b";
            break;
        case 12:
            return "c";
            break;
        case 13:
            return "d";
            break;
        case 14:
            return "e";
            break;
        case 15:
            return "f";
            break;
        case 16:
            return "g";
            break;
        case 17:
            return "h";
            break;
        case 18:
            return "i";
            break;
        case 19:
            return "j";
            break;
        case 20:
            return "k";
            break;
        case 21:
            return "l";
            break;
        case 22:
            return "m";
            break;
        case 23:
            return "n";
            break;
        case 24:
            return "o";
            break;
        case 25:
            return "p";
            break;
        case 26:
            return "q";
            break;
        case 27:
            return "r";
            break;
        case 28:
            return "s";
            break;
        case 29:
            return "t";
            break;
        case 30:
            return "u";
            break;
        case 31:
            return "v";
            break;
        case 32:
            return "w";
            break;
        case 33:
            return "x";
            break;
        case 34:
            return "y";
            break;
        case 35:
            return "z";
            break;
        }
}

void initialization()
{
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            st.push(search36(temp % 36));
            temp /= 36;
        }
        while (!st.empty())
        {
            tax[i].ID += st.top();
            st.pop();
        }
    }
}

void divide(const array<int, 30> &c)
{
    for (int i = 1; i <= k; i++)
    {
        int temp = c.at(i - 1);
        for (int j = 1; j <= n; j++)
        {
            if (j < temp || j % 36 < temp)
                tax[j].cuc = i;
            if (i == k && tax[j].cuc == 0)
                tax[j].cuc = i + 1;
        }
    }
}

string search(const int &q, const int &p)
{
    int dem = 0;
    if (p % 2 == 0)
        for (int i = n; i > 0; i--)
        {
            if (tax[i].cuc = p / 2)
                dem++;
            if (dem == q)
                return tax[i].ID;
        }
    else
        for (int i = 1; i <= n; i++)
        {
            if (tax[i].cuc = (p + 1) / 2)
                dem++;
            if (dem == q)
                return tax[i].ID;
        }
}
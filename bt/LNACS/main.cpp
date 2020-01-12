#include <fstream>
#include <iostream>

using namespace std;

const int MAX = 20;

int a[MAX];
int b[MAX];
int m, n;
int f[MAX][MAX];

void in();

int main()
{
    in();
    f[0][0] = 0;
    for(int i=1; i<=m; i++)
        f[i][1]=(a[i-1]==b[0])?1:f[i-1][1];
    for(int j=1; j<=n; j++)
        f[1][j]=(a[0]==b[j-1])?1:f[1][j-1];
    for(int i=2; i<=m; i++)
        for(int j=2; j<=n; j++)
    {
        f[i][j]=max(f[i][j-1],max(f[i-1][j],f[i-1][j-1]));
        if(a[i-1]==b[j-1])
            f[i][j]=max(f[i][j],f[i-2][j-2]+1);
    }
    cout<<f[m][n] << endl;
}

void in()
{
    ifstream infile;
    int i;
    infile.open("LNACS.INP");
    infile >> m;
    infile >> n;
    for (i = 0; i < m; i++)
    {
        infile >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        infile >> b[i];
    }
    infile.close();
}

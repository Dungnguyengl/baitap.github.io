#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class General
{
private:
    string S[100];
    int nSoluong;
    ifstream infile;
    ofstream outfile;

public:
    General();
    void kiemtrachuoi();
    void ghichuoi(const int &i);
};

General::General()
{
    infile.open("chuoiktin.txt");
    infile >> nSoluong;
    for (int i = 0; i < nSoluong; i++)
    {
        infile >> S[i];
    }
    infile.close();
    outfile.open("chuoiktout.txt");
    outfile.clear();
    outfile.close();
}

void General::kiemtrachuoi()
{
    for (int i = 0; i < nSoluong - 1; i++)
    {
        int dem = 0;
        for (int j = 0; j < nSoluong; j++)
        {
            for (int x = 0; x < S[i].size() && x < S[j].size(); x++)
                if (S[i] == S[j])
                {
                    dem++;
                }
        }

        if (dem % 2 == 1)
        {
            ghichuoi(i);
        }
    }
}

void General::ghichuoi(const int &i)
{
    outfile.open("chuoiktout.txt", ios::app);
    outfile << S[i] << endl;

    outfile << endl;
    outfile.close();
}

int main()
{
    General general;
    general.kiemtrachuoi();
    return 0;
}
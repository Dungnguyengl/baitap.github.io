#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    int RowOfArray, ColOfArray;

    cout << "==================="
         << "MA TRAN!"
         << "==================="
         << "\n";
    cout << "nhap so hang: ";
    cin >> RowOfArray;
    cout << "nhap so cot: ";
    cin >> ColOfArray;

    int *arr = new int[RowOfArray * ColOfArray];
    arr = make_matran(RowOfArray, ColOfArray);

    show_matran(arr, RowOfArray, ColOfArray);

    cout << "TBC = " << TBC_duongcheochinh(arr, RowOfArray, ColOfArray) << endl;

    cout << "tong hang 1 = " << Sum(arr, 1, ColOfArray) << endl;

    cout << "ham co tong lon nhat la: " << MaxSum(arr, RowOfArray, ColOfArray);

    Print_Col(arr, RowOfArray, ColOfArray, 1);

    return 0;
} //main

int getSingleIndex(const int &row, const int &col, const int &ColOfArray)
{
    return (row * ColOfArray) + col;
}

int *make_matran(int &RowOfArray, int &ColOfArray)
{
    int *arr = new int[RowOfArray * ColOfArray];
    cout << "NHAP MA TRAN!" << endl;
    for (size_t x = 0; x < ColOfArray; x++)
    {
        for (size_t y = 0; y < RowOfArray; y++)
        {
            cout << "nhap phan tu[" << x + 1 << "][" << y + 1 << "]: ";
            cin >> arr[getSingleIndex(x, y, ColOfArray)];
        }
    }
    return arr;
}

void show_matran(const int *arr, const int &RowOfArray, const int &ColOfArray)
{
    cout << "IN MA TRAN!"
         << "(" << ColOfArray << "x" << RowOfArray << ")" << endl;
    for (size_t x = 0; x < ColOfArray; x++)
    {
        for (size_t y = 0; y < RowOfArray; y++)
        {
            cout << arr[getSingleIndex(x, y, ColOfArray)] << "\t";
        }
        cout << "\n";
    }
}

double TBC_duongcheochinh(const int *arr, const int &RowOfArray, const int &ColOfArray)
{
    double TBC = 0;
    int i;
    for (i = 0; i < RowOfArray && i < ColOfArray; ++i)
        TBC += arr[getSingleIndex(i, i, ColOfArray)];
    TBC /= i;
    return TBC;
}

int Sum(const int *arr, const int &row, const int &ColOfArray)
{
    int SUM = 0;
    for (size_t i = 0; i < ColOfArray; ++i)
    {
        SUM += arr[getSingleIndex(row - 1, i, ColOfArray)];
    }
    return SUM;
}

int MaxSum(const int *arr, const int &RowOfArray, const int &ColOfArray)
{
    int *Sum = new int[RowOfArray];
    for (size_t x = 0; x < RowOfArray; x++)
    {
        for (size_t y = 0; y < ColOfArray; y++)
        {
            Sum[x] += arr[getSingleIndex(x, y, ColOfArray)];
        }
    }
    int Max = Sum[0];
    int temp;
    for (int i = 1; i < RowOfArray; ++i)
    {
        if (Max != max(Max, Sum[i]))
            temp = i;
    }
    delete[] Sum;
    return temp + 1;
}

void Print_Col(const int *arr, const int &RowOfArray, const int &ColOfArray, const int &col)
{
    cout << "CAC PHAN TU CUA COT " << col << " !" << endl;
    for (size_t i = 0; i < RowOfArray; ++i)
    {
        cout << arr[getSingleIndex(i, col - 1, ColOfArray)] << endl;
    }
}

// function.h
#ifndef _FUNCTION_
#define _FUNCTION_

void show_matran(const int *, const int &, const int &);               //in ma tran
void Print_Col(const int *arr, const int &, const int &, const int &); //cot bat ki

double TBC_duongcheochinh(const int *, const int &, const int &); //tinh trung binh cong duong cheo chinh

int MaxSum(const int *arr, const int &, const int &);      //tong hang lon nhat
int Sum(const int *arr, const int &, const int &);         //tong mot hang bat ki
int *make_matran(int &, int &);                            //tao ma tran
int getSingleIndex(const int &, const int &, const int &); //xac dinh vi tri trong ma tran

#endif // _FUNCTION_
#include<iostream> 
using namespace std;

void swapNumber(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	void(*ptrSwap) (int &, int &) = swapNumber;

	int a = 5, b = 10;
	cout << "Before: " << a << " " << b << endl;

	// gọi hàm tường minh
	(*ptrSwap)(a, b);
	cout << "After:  " << a << " " << b << endl;

	// hoặc gọi hàm ngầm định
	ptrSwap(a, b);
	cout << "After:  " << a << " " << b << endl;

	return 0;
}

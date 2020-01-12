#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	int nInput;
	cout << "Enter n(integer): ";
	cin >> nInput;

	int nSum = tinhTongCacChuSoDungWhile(nInput);
	cout << "Tong cac chu so: " << nSum << endl;

	return 0;
}

int tinhTongCacChuSoDungWhile(int nInput)
{
	int nRem, nSum = 0;
	while (nInput != 0)
	{
		// Lấy chữ số cuối của số nguyên sử dụng toán tử chia lấy dư (Modulus)
		nRem = nInput % 10;

		// Cộng chữ số cuối vào biến Sum
		nSum = nSum + nRem;

		// Xóa chữ số cuối bằng cách sử dụng toán tử chia lấy phần nguyên (Division)
		nInput = nInput / 10;
	}
	return nSum;
}

int tinhTongCacChuSoDungFor(int nInput)
{
	int nRem, nSum = 0;
	for (; nInput != 0;)
	{
		nRem = nInput % 10;
		nSum = nSum + nRem;
		nInput = nInput / 10;
	}
	return nSum;
}

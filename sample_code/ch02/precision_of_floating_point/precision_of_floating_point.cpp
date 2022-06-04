﻿#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float float_value = 9.87654321f; //float는 리터럴 끝에 ‘f’
	double double_value = 9.87654321987654321; //double은 리터럴 끝에 붙이는 것이 없음
	long double long_double_value = 9.87654321987654321l; //long double은 리터럴 끝에 ‘l’

	cout << "float : " << sizeof(float) << " bytes" << endl;
	cout << "float_value : " << setprecision(numeric_limits<float>::digits10 + 1) << float_value << endl << endl;

	cout << "double : " << sizeof(double) << " bytes" << endl;
	cout << "double_value : " << setprecision(numeric_limits<double>::digits10 + 1) << double_value << endl << endl;

	cout << "long double : " << sizeof(long double) << " bytes" << endl;
	cout << "long_double_value : " << setprecision(numeric_limits<long double>::digits10 + 1) << long_double_value << endl << endl;

	return 0;
}

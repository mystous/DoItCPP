#include <iostream>

using namespace std;

void func_throw()
{
    cout << endl;
    cout << "func_throw()" << endl;
    cout << "before throw -1" << endl;
    throw - 1;	//정수 타입 예외 던지기
    cout << "after throw -1" << endl;
}

void func_2()
{
    cout << endl;
    cout << "func_2()" << endl;
    cout << "before func_throw()" << endl;
    func_throw();
    cout << "after func_throw()" << endl;
}

void func_1()
{
    cout << "func_1()" << endl;
    cout << "before func_2()" << endl;
    func_2();
    cout << "after func_2()" << endl;
}


int main()
{
    try
    {
        func_1();
    }
    catch (int exec)	//정수 타입 예외 받기
    {
        cout << endl;
        cout << "catch " << exec << endl;
    }

    return 0;
}

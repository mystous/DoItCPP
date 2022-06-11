#include <iostream>

using namespace std;

void change_negative(int* _val)	//포인터 변수를 매개 변수로 사용
{
    if (*_val > 0)
    {
        *_val = -(*_val);
    }
}

int main()
{
    int a = 3, b = -3;

    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    change_negative(&a);	//a변수의 주소값을 매개변수로 전달
    change_negative(&b);	//b변수의 주소값을 매개변수로 전달

    cout << "change_negative(a) : " << a << endl;
    cout << "change_negative(b) : " << b << endl;

    return 0;
}

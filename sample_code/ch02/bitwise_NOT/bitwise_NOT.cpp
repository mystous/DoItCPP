#include <iostream>

using namespace std;

int main()
{
    unsigned int value = 0x00000000; //0을 hex 값 (16진수)로 표현한 값 입니다.

    value = ~value;
    cout << hex << value << endl;
}

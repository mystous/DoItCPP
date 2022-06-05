#include <iostream>

using namespace std;

int main()
{
    int a = 7;
    int b = 5;
    int result;

    if (a > b)
        result = a; //a > b가 true 이면, result에 a 값 저장
    else
        result = b; //a > b가 false 이면, result에 b 값 저장

    cout << "result = " << result << endl;

    return 0;
}

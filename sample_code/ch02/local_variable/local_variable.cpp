#include <iostream>

using namespace std;

int add(int x, int y) //매개변수로 정의된 x, y는 add함수 안에서만 효력이 있습니다.
{
    return x + y;
}

int main()
{
    int x, y; //main함수에서의 x, y는 main함수 안에서만 효력이 있습니다.
    x = 1;
    y = 2;

    //add함수를 호출할 때, main함수의 x, y에 있는 값은 add함수의 x, y로 복사됩니다.
    cout << "result : " << add(x, y) << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int value = 10;
    int& ref_value = value;

    int value2 = 20;
    ref_value = value2; //레퍼런스 재지정을 의도했으나, 의도와 다르게 동작하는 부분

    cout << "value: " << value << endl;
    cout << "ref_value: " << ref_value << endl;

    return 0;
}

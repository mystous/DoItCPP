#include <iostream>

using namespace std;

const long double km_per_mile = 1.609344L;

long double operator"" _km(long double val) //_km 사용자 리터럴 정의
{
    return val;
}

long double operator"" _mi(long double val) //_mi 사용자 리터럴 정의
{
    return val * km_per_mile; //mile은 km 단위로 변환
}

int main()
{
    long double distance_1 = 1.0_km; //km는 그대로 저장
    long double distance_2 = 1.0_mi;  //mile은 km 단위로 변환되어 저장

    cout << distance_1 + distance_2 << " km" << endl; //km 값으로 출력

    return 0;
}

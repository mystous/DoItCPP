#include <iostream>
#include <numbers>

using namespace std;
using namespace std::numbers;

int main() {
  cout.precision(20);
  cout << "수학 상수 출력" << endl
    << "자연대수 e : " << e << endl
    << "자연로그2 ln2 : " << ln2 << endl
    << "자연로그10 ln10 : " << ln10 << endl
    << "밑이2인 로그 log2 : " << log2e << endl
    << "밑이10인 로그 log10 :" << log10e << endl
    << "원주율 : " << pi << endl
    << "루트 2 : " << sqrt2 << endl
    << "루트 3 : " << sqrt3 << endl
    << "오일러-마스케로니 상수 :" << egamma << endl
    << "황금비 : " << phi << endl;
  return 0;
}
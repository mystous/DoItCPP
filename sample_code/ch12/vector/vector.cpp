#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;
  vec.push_back(0);  // 맨 뒤에 0 추가
  vec.push_back(1);  // 맨 뒤에 1 추가
  vec.push_back(2);  // 맨 뒤에 2 추가

  for (int i = 0; i < 3; i++) {
    cout << "vec 의 " << i + 1 << " 번째 원소 : " << vec[i] << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;
  vec.push_back(0);  // 맨 뒤에 0 추가
  vec.push_back(1);  // 맨 뒤에 1 추가
  vec.push_back(2);  // 맨 뒤에 2 추가
  vec.push_back(3);  // 맨 뒤에 3 추가
  vec.push_back(4);  // 맨 뒤에 4 추가
  vec.push_back(5);  // 맨 뒤에 5 추가

  for (int i = 0; i < 6; i++) {
    cout << "vec 의 " << i + 1 << " 번째 원소 : " << vec[i] << endl;
  }
}

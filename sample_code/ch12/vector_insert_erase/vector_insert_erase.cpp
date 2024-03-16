#include <iostream>
#include <vector>

using namespace std;

// 벡터의 모든 원소를 출력하는 함수
template <typename T>
void print_vector_all(vector<T>& vec) {
  cout << "벡터 내 원소 개수 : " << vec.size() << endl;

  // 벡터의 모든 원소 출력
  for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl << "---------------------" << endl;
}

int main() {
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  cout << "원본" << endl;
  print_vector_all(vec);

  // 벡터에 원소 삽입
  vec.insert(vec.begin() + 3, 25);    // vec[3] 앞에 25 추가
  cout << "insert 결과" << endl;
  print_vector_all(vec);

  // 벡터에서 원소 삭제
  vec.erase(vec.begin() + 3);         // vec[3] 제거
  cout << "erase 결과" << endl;
  print_vector_all(vec);

  return 0;
}
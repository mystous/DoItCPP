#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers = { 1, 2, 3, 4, 5 };

  cout << "찾고 싶은 숫자를 입력하세요: ";
  int target;
  cin >> target;

  // 입력받은 숫자를 찾아서 해당 위치를 반환
  vector<int>::iterator it = find(numbers.begin(), numbers.end(), target);

  if (it != numbers.end()) {
    cout << "찾은 위치: " << distance(numbers.begin(), it) << endl;
  }
  else {
    cout << "찾을 수 없음" << endl;
  }

  return 0;
}

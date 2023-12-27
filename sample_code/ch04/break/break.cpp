#include <iostream>

using namespace std;

int main() {
  for (int count = 0; count < 10; count++) {
    cout << "count: " << count << endl;
    if (count == 5) {
      cout << "break로 반복문 탈출" << endl;
      break;
    }
  }
  cout << "반복문 종료" << endl;
  return 0;
}

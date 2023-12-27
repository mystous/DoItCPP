#include <iostream>

using namespace std;

int average(int _array[], int _count) {
  int sum = 0;
  for (int i = 0; i < _count; i++) {
    sum += _array[i];
  }

  return (sum / _count);
}

int main() {
  int score[5] = { 90, 75, 80, 100, 65 };

  cout << "평균점수 : " << average(score, 5) << endl;

  return 0;
}

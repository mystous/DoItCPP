import std.core; // 모듈 가져오기
using namespace std;

int main(void) {
  array<int, 10> numbers{ 7, 8, 2, 5, 3, 9, 0, 4, 1, 6 };

  for (auto& value : numbers) {
    cout << value << " , ";
  }
  cout << endl;

  return 0;
}
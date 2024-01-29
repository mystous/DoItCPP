#include <iostream>
#include <string>

using namespace std;

void compare_result(int result) {
  if (result == 0) {
    cout << result << " = 두 문자열이 같음" << endl;
  }
  else if (result > 0) {
    cout << result << " = 대상 문자열이 더 길거나 일치하지 않는 첫 번째 문자가 더 큼" << endl;
  }
  else if (result < 0) {
    cout << result << " = 대상 문자열이 더 짧거나 일치하지 않는 첫 번째 문자가 더 작음" << endl;
  }
}

int main() {
  // 1. s1, s2 문자열이 같을 때 
  string s1 = "Hello";
  string s2 = "Hello";
  int result = s1.compare(s2);
  compare_result(result);

  // 2. s1 문자열의 길이가 더 짧을 때
  s1 = "Hello";
  s2 = "Hello World";
  result = s1.compare(s2);
  compare_result(result);

  // 3. s1 문자열의 첫 번째 문자가 알파벳 순서상 먼저 나올 때
  s1 = "cat";
  s2 = "dog";
  result = s1.compare(s2);
  compare_result(result);

  // 4. s1 문자열의 길이가 더 클 때
  s1 = "Hello World";
  s2 = "Hello";
  result = s1.compare(s2);
  compare_result(result);

  // 5. s1 문자열의 길이가 더 짧지만, 
  //    일치하지 않는 첫 번째 문자가 알파벳 순서상 늦게 나올 때
  s1 = "cat";
  s2 = "apple";
  result = s1.compare(s2);
  compare_result(result);

  return 0;
}

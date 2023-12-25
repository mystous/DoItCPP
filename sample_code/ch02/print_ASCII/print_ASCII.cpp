#include <iostream>

using namespace std;

int main() {
  cout << "아스키 코드 출력하기 [32 ~ 126]:\n";

  for (char i = 32; i <= 126; i++)    // 32부터 126까지 차례로 1씩 증가하며 반복
  {
    // 아스키 코드를 출력할 때 공백을 넣고 16개마다 줄 바꾸기
    cout << i << ((i % 16 == 15) ? '\n' : ' ');
  }

  return 0;
}

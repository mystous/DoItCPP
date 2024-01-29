#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> myStack;

  // 스택에 데이터 추가
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);

  // 스택의 맨 위쪽 값 확인
  cout << "맨 위 요소: " << myStack.top() << endl;

  // 스택에서 데이터 제거(맨 위쪽 데이터 꺼내기)
  myStack.pop();
  cout << "맨 위 요소 제거 후, 새로운 맨 위 요소: " << myStack.top()
    << endl;

  // 스택의 크기(데이터 개수) 확인
  cout << "스택 크기: " << myStack.size() << endl;

  // 스택이 비었는지 확인
  if (myStack.empty()) {
    cout << "스택이 비었습니다." << endl;
  }
  else {
    cout << "스택은 비어 있지 않습니다." << endl;
  }

  return 0;
}
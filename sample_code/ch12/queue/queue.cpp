#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> myQueue;

  // 삽입하기
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);

  cout << "큐의 맨 앞: " << myQueue.front() << endl;  // front
  cout << "큐의 맨 뒤: " << myQueue.back() << endl;   // back

  // 꺼내기
  myQueue.pop();

  cout << "pop 후 맨 앞: " << myQueue.front() << endl;  // pop 후 front
  cout << "pop 후 맨 뒤: " << myQueue.back() << endl;   // pop 후 back

  // 비었는지 확인하기
  cout << "큐가 비어 있나요? " << (myQueue.empty() ? "네" : "아니오") << endl;

  // 크기 구하기
  cout << "큐의 크기: " << myQueue.size() << endl;

  return 0;
}

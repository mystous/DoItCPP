#include <iostream>
using namespace std;

class character {
public:
  character() {
    cout << "character 클래스 생성자" << endl;
  };
};

int main() {
  character player;
  return 0;
}
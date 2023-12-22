#include <iostream>
using namespace std;

class character {
public:
  character() : location{ 0,0 } {
  };
  // x, y 좌표를 매개변수로 같는 함수
  void move(int x, int y) {
    location[0] = x;
    location[1] = y;
    cout << location[0] << ", " << location[1] << "로 이동" << endl;
  };
  // x, y 배열과 배열 크기를 매개변수로 가지는 함수
  void move(int x[], int y[], int spot_count) {
    for (int i = 0; i < spot_count; ++i) {
      location[0] = x[i];
      location[1] = y[i];
      cout << i + 1 <<  "번째:" << location[0] << ", " << location[1] << "로 이동" << endl;
    }
  }

protected:
  int location[2];
};

int main(void) {
  character character_obj;
  int x_list[3] = { 10, 15, 20 };
  int y_list[3] = { 10, 15, 20 };

  // x, y 좌표를 매개변수로 가지는 함수 호출
  character_obj.move(10, 10); 
  cout << endl;
  // x, y 배열과 배열 크기를 매개변수로 가지는 함수 호출
  character_obj.move(x_list, y_list, 3); 
}

### 동료들에게 필요한 함수 만들기
여러분이 동료들과 함께 그래픽 처리를 위한 프로그램을 만들고 있습니다. 함께 일하는 동료를 위해 API를 만들고 있습니다. 이번에 만들 함수는 RGB 값 여러 개를 입력받아 R, G, B 각각의 평균값으로 계산해서 반환하는 함수입니다. RGB는 1개부터 무한대로 입력할 수 있습니다. 함수는 폴드 표현식을 사용해서 구현해 보세요.
<br/><br/>

---

#### 모범 답안
##### 답안
```cpp
#include <iostream>

using namespace std;

class RGB {
public:
  RGB(int r_value, int g_value, int b_value) : r(r_value), g(g_value), b(b_value){};
  void print() { cout << "R(" << r << "), G(" << g << "), B(" << b << ")" << endl; };
private:
  int r, g, b;
  friend class graphic_object;
};

class graphic_object {
public:
  template<typename RGB>
  void build_rgb(RGB rgb_value) {
    average_rgb.r += rgb_value.r;
    average_rgb.g += rgb_value.g;
    average_rgb.b += rgb_value.b;
    count++;
    average_rgb.r /= count;
    average_rgb.g /= count;
    average_rgb.b /= count;

  };
  template<typename RGB, typename... RGBs>
  void build_rgb(RGB rgb_value, RGBs... rgb_list) {
    average_rgb.r += rgb_value.r;
    average_rgb.g += rgb_value.g;
    average_rgb.b += rgb_value.b;
    count++;
    build_rgb(rgb_list...);
  }
  RGB get_average_rgb() { return average_rgb; };
private:
  RGB average_rgb = RGB(0, 0, 0);
  int count = 0;
};

int main()
{
  graphic_object graphic;
  RGB rgb1(127, 231, 23), rgb2(0, 17, 123), rgb3(12, 123, 0), rgb4(7, 31, 230), rgb5(56, 22, 255);

  graphic.build_rgb(rgb1, rgb2, rgb3, rgb4, rgb5);
  RGB result = graphic.get_average_rgb();
  result.print();

  return 0;
}
```
* RGB 클래스의 private 멤버를 소스코드 간결성을 위하여 graphic_object를 friend class로 선언하였습니다. 일반적인 코드에서는 꼭 필요한 경우만 friend class로 선언해 주세요.
###### 실행 결과
```
R(40), G(84), B(126)
```
##### 설명
제일 중심이 되는 함수는 build_rgb입니다. 매개변수 팩이 들어 오면 처리 하는 두가지 종류의 함수로 되어 있습니다. 중간 RGB는 평균 값 계산을 위하여 더해 놓고 가장 마지막에 평균을 냅니다.

재귀적으로 호출되는 함수와 말단 함수의 모양을 잘 살펴 보세요.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

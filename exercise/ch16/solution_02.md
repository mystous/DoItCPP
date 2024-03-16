#### 문제 2 그래픽 프로그램 업그레이드
[문제 1]에서 만든 API를 활용하다 보니 R, G, B 값을 따로 입력받지 않고 #0F0F0F 형태의 문자열로 입력하게 변경해 달라는 요청을 받았습니다. 새로운 요청에 맞는 API를 만들면서 호출하는 모든 소스 코드를 찾아서 고치는 것이 시간이 너무 많이 걸린다는 것을 알았습니다. 신규 API만 남기고 예전 API는 이제 사용 되지 않는다는 것을 컴파일 단계에서 알리고 싶습니다. 여러분의 동료와 자신을 위해서 API를 고쳐 보세요.
<br/><br/>

---


#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <sstream>

using namespace std;

class RGB {
public:
  RGB(string rgb_string);
  RGB(int r_value, int g_value, int b_value) = delete;
  void print() { cout << "R(" << r << "), G(" << g << "), B(" << b << ")" << endl; };
private:
  int r, g, b;
  friend class graphic_object;
};

int hex2decimal(const std::string& hex) {
  int decimal;
  istringstream(hex) >> std::hex >> decimal;
  return decimal;
}

RGB::RGB(string rgb_string) {
  r = hex2decimal(rgb_string.substr(1, 2));
  g = hex2decimal(rgb_string.substr(3, 2));
  b = hex2decimal(rgb_string.substr(5, 2));
}

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
  // [문제 2]부터 지원하지 않는 생성자 사용시 오류 발생
  //RGB average_rgb = RGB(0, 0, 0);
  RGB average_rgb = RGB("#000000");
  int count = 0;
};

int main()
{
  graphic_object graphic;
  // [문제 2]부터 지원하지 않는 생성자 사용시 오류 발생
  //RGB rgb1(127, 231, 23), rgb2(0, 17, 123), rgb3(12, 123, 0), rgb4(7, 31, 230), rgb5(56, 22, 255);
  RGB rgb1("#7FE717"), rgb2("#00117B"), rgb3("#0C7B00"), rgb4("#071FE6"), rgb5("#3816FF");

  graphic.build_rgb(rgb1, rgb2, rgb3, rgb4, rgb5);
  RGB result = graphic.get_average_rgb();
  result.print();

  return 0;
}
```
###### 실행결과
```
R(40), G(84), B(126)
```
##### 설명
RGB를 별도로 입력 받던 생성자를 #FFFFFF 형식의 16진수 문자열로 입력 받게 수정하였습니다. 이제 각각 입력 받던 생성자는 = delete;로 더이상 지원하지 않는다는 의사를 표현하였습니다.

이전 생성자를 호출하면 오류가 발생하여 API가 수정되었다는 사실을 알 수 있습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

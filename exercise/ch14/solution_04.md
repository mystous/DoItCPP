#### 문제 4 정렬 만들어 보기
표준 라이브러리에서 정렬을 수행하는 sort 함수는 데이터를 비교하는 compare 함수를 콜백으로 입력받습니다. 비슷한 형식으로 여러분이 직접 정렬 알고리즘을 만들어 보세요. 이때 콜백 함수는 std::function을 사용합니다.
<br/><br/>

---


#### 모범 답안
##### 답안
```cpp
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

void print_all(vector<double> data) {
  for (auto && element : data) {
    cout << element << " , ";
  }
  cout << endl;
}

bool compare(double a, double b)
{
  if (a > b) {
    return false;
  }
  return true;
}

int main()
{
  vector<double> data = { 1.203, 2.45, 9.54, 9.51, 5.43, 1.201, 6.43, 8.12, 3.11, 4.20 };
  vector<double> data_ = data;

  function<bool(double a, double b)> comp = compare;
  function<bool(double, double)> comp_reverse = [](double a, double b) {
    if (a > b) {
      return true;
    }
    return false;};

  cout << "정렬 전 원 데이터(실수)" << endl;
  print_all(data);
  sort(data.begin(), data.end(), comp);
  cout << endl<< "오름차순 정렬 결과" << endl;
  print_all(data);
  sort(data_.begin(), data_.end(),  comp_reverse);
  cout << endl << "내림차순 정렬 결과" << endl;
  print_all(data_);

  return 0;
}
```

###### 실행 결과
```
정렬 전 원 데이터(실수)
1.203 , 2.45 , 9.54 , 9.51 , 5.43 , 1.201 , 6.43 , 8.12 , 3.11 , 4.2 ,

오름차순 정렬 결과
1.201 , 1.203 , 2.45 , 3.11 , 4.2 , 5.43 , 6.43 , 8.12 , 9.51 , 9.54 ,

내림차순 정렬 결과
9.54 , 9.51 , 8.12 , 6.43 , 5.43 , 4.2 , 3.11 , 2.45 , 1.203 , 1.201 ,
```

##### 설명
모범 답안에서는 오름차순 정렬과 내림차순 정렬을 std::function으로 콜백을 지정합니다. 오름차순은 함수 포인터를 std::function에 지정하고 내일차순은 람다 함수를 지정하였습니다.

오름차순, 내림차순은 값 비교의 결과를 반대로 판단하면 됩니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

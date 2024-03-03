#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <random>

using namespace std;

int main() {
  // 난수 엔진 설정
  random_device rd;
  mt19937 gen(rd());

  // 사용자 입력
  int num_throws;
  cout << "주사위를 몇 번 던질까요? ";
  cin >> num_throws;

  // 시뮬레이션 수행 및 결과 출력
  for (int i = 0; i < num_throws; ++i) {
    int dice1 = gen() % 6 + 1;
    int dice2 = gen() % 6 + 1;
    int sum = dice1 + dice2;
    cout << "주사위 " << i + 1 << "번째 던지기 결과: " << dice1 << " + " << dice2 << " = " << sum << endl;
  }

  return 0;
}
```

##### 설명
실행결과
```cpp
주사위를 몇 번 던질까요? 3
주사위 1번째 던지기 결과: 1 + 5 = 6
주사위 2번째 던지기 결과: 3 + 5 = 8
주사위 3번째 던지기 결과: 2 + 3 = 5
```

<li>random_device를 사용하여 시스템에서 난수 엔트로피를 얻습니다.</li>
<li>mt19937 엔진을 사용하여 random_device에서 얻은 엔트로피를 기반으로 난수를 생성합니다.</li>
#### 문제 람다 표현식 활용
여러분은 한 기관의 입시 성적을 처리 중입니다. 시험은 국어, 영어, 수학, 과학 4과목이고 모두 (~~체점~~)채점이 완료되어 응시자 숫자만큼의 구조체에 저장되어 있습니다. 여러분은 총 10,000명의 합격자 숫자를 계산해야 합니다.
* 4과목 평균이 80점 이상이면 합격, 65점 이하면 과락입니다.
* 학생별 합격 여부는 저장하지 않고 조건을 만족하는 합격자 숫자만 계산합니다.
<br/><br/>

---


#### 모범 답안
##### 답안
```cpp
#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct scores {
  int korean;
  int english;
  int math;
  int science;
};

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 100);

  vector<scores> student_scores;
  const int student_count = 10000;
  
  for (int i = 0; i < student_count; ++i) {
    student_scores.push_back(scores(dis(gen), dis(gen), dis(gen), dis(gen)));
  }

  int pass_student = [](vector<scores> &student_score_list)->int {
    int pass_numbers = 0;
    for (auto&& score : student_score_list) {
      double average = (score.korean + score.english + score.math + score.science) / 4.0;
      if (average >= 80 && score.korean >= 65 && score.english >= 65 && score.math >= 65 && score.science >= 65) {
        pass_numbers++;
      }
    }
    return pass_numbers;
  }(student_scores);

  cout << "합격자 수: " << pass_student << endl;

  return 0;
}
```
###### 실행결과
```
합격자 수: 117
```
* 합격자 수는 점수가 난수로 만들어졌기 때문에 매번 변경 됩니다.
##### 설명
총 10,000개의 4과목 점수를 가지고 있는 구조체를 vector에 저장 후 평균 80이상 학생수를 저장하는 변수인 pass_student를 선언하면서 람다 표현식으로 vector를 순회 하면서 평균 80이상을 학생수를 계산하여 바로 저장합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

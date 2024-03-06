### 문제 1 자료형을 추론하는 auto
auto는 모던 C++의 작지만 영향력이 큰 변화 중 한 가지입니다. 도서 목록을 저장하고 불러올 수 있는 C++ 프로그램을 작성하면서 auto와 범위 기반 for 문을 사용해 보세요.
<br/><br/>

---

#### 모범 답안
##### 답안
```cpp
#include <iostream>
#include <vector>
using namespace std;

class library {
public:
  void print_book_list();
  void add_book(string title) { book_list.push_back(title); };
private:
  vector<string> book_list;
};

void library::print_book_list() {
  cout << "책 리스트 출력:" << endl;
  for (auto&& title : book_list) {
    cout << title << endl;
  }
}

int main()
{
  library book_manager;

  book_manager.add_book("내일을 향해 달리다.");
  book_manager.add_book("바람과 함께 슁슁");
  book_manager.add_book("성공하는 사람들의 7가지 속삭임");
  book_manager.add_book("1980년대");

  book_manager.print_book_list();

  return 0;
}
```

###### 실행 결과
```
책 리스트 출력:
내일을 향해 달리다.
바람과 함께 슁슁
성공하는 사람들의 7가지 속삭임
1980년대
```

[문제로 돌아 가기](README.md "문제로 돌아 가기")

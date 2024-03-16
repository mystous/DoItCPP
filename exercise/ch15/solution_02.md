#### 문제 2 도서 관리 프로그램 업그레이드하기
[문제 1]의 도서 관리 프로그램을 업그레이드합니다. 홀수 인덱스를(1, 3) 가진 책의 제목만 출력하는 함수를 만들려고 합니다. 이때 책 제목은 바로 앞 인덱스의 책 제목과 함께 출력되게 만들어 보세요. 예시) 0번째 책 제목 ‘국어’, 1번째 책 제목 ‘수학’인 경우, 1번째 책 제목을 ‘국어책 다음 수학책’으로 출력합니다.
<br/><br/>

---


#### 모범 답안 과 설명
##### 답안
```cpp
#include <iostream>
#include <vector>
using namespace std;

class book {
public:
  book(string title_param, string author_param, unsigned int  publish_year_param, string isbn_param)
    : title(title_param), author(author_param), publish_year(publish_year_param), isbn(isbn_param) {};
private:
  string title = "";
  string author = "";
  unsigned int publish_year = 1900;
  string isbn = "";

  friend class library;
};

class library {
public:
  void initialize();
  tuple<string, string, int, string> get_book_info(unsigned int index);
private:
  vector<book> book_list;
};

tuple<string, string, int, string> library::get_book_info(unsigned int index) {

  auto&& book = book_list[index];
  return make_tuple(book.title, book.author, book.publish_year, book.isbn);
}

void library::initialize() {
  book book1("내일을 향해 달리다.", "홍길동", 2009, "00000001");
  book_list.push_back(book1);
  book book2("바람과 함께 슁슁", "아무개", 2020, "00124001");
  book_list.push_back(book2);
  book book3("성공하는 사람들의 7가지 속삭임", "유명인", 2019, "02528301");
  book_list.push_back(book3);
  book book4("1980년대", "피터", 2022, "19224981");
  book_list.push_back(book4);
  book book5("빅앤 스몰 브라더", "암자", 2024, "99128178");
  book_list.push_back(book5);
}

void print_book_list(library& lib, unsigned int index) {
  if (0 == index % 2) {
    return;
  }
  auto [title_prev, author_prev, year_prev, isbn_prev] = lib.get_book_info(index - 1);
  auto [title, author, year, isbn] = lib.get_book_info(index);

  cout << title_prev << "책 다음 " << title << "책" << endl;
}

int main()
{
  library book_manager;
  book_manager.initialize();

  for (int i = 0; i < 5; ++i) {
    print_book_list(book_manager, i);
  }
  return 0;
}
```
###### 실행결과
```
내일을 향해 달리다.책 다음 바람과 함께 슁슁책
성공하는 사람들의 7가지 속삭임책 다음 1980년대책
```

##### 설명
[문제 1]에서 print_book_list 소스코드만 변경되었습니다. 인덱스가 홀수인 경우만 함수의 기능이 실행됩니다. 인자로 들어온 인덱스와 해당 인덱스보다 하나 적은 인덱스 두개의 책 제목을 반환 받아서 한 번에 출력합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

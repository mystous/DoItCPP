### 문제 1 도서 관리 프로그램
다음 요구 사항을 만족하는 도서 관리 프로그램을 만들어 보세요.
1) 도서는 제목, 저자, ~~지은이,~~(오탈자 삭제) 출판 연도, ISBN 정보로 저장됩니다.
2) 도서 목록은 이미 저장되어 있습니다. 추가 기능은 구현하지 않습니다.
3) 도서 목록의 처음 5개를 가져와서 화면에 보여 주는 기능이 있습니다.
4) 이때 구조체나 참조에 의한 호출을 사용하지 않고 튜플과 구조적 바인딩을 이용해 도서 정보를 가져와
화면에 출력합니다.
5) 도서 목록을 가져오는 기능은 함수로 구현해야 합니다. 도서의 순서(0, 1, 2, 3, 4)를 매개변수로 받고
도서 정보를 반환합니다.
<br/><br/>

---

#### 모범 답안
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
  auto [title, author, year, isbn] = lib.get_book_info(index);
  cout << "책 [" << index << "] - (" << title << ", " << author << ", " << year << ", " << isbn << ")" << endl;
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
책 [0] - (내일을 향해 달리다., 홍길동, 2009, 00000001)
책 [1] - (바람과 함께 슁슁, 아무개, 2020, 00124001)
책 [2] - (성공하는 사람들의 7가지 속삭임, 유명인, 2019, 02528301)
책 [3] - (1980년대, 피터, 2022, 19224981)
책 [4] - (빅앤 스몰 브라더, 암자, 2024, 99128178)
```

##### 설명
print_book_list함수에서는 library 클래스에서 book 클래스 객체를 반환 받는 것이 아니라 제목, 저자, 출판 연도, ISBN를 튜블과 구조적 바인딩으로 반환 받아서 출력합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

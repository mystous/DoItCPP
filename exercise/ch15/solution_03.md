#### 문제 3 도서 목록 갱신하기
[문제 1]의 도서 관리 프로그램을 운영하다가 ISBN 체계가 바뀌었다는 소식을 접했습니다. ISBN에 ‘C++’ 이라는 접두어를 붙여야 합니다. 모든 도서 목록을 읽어서 ISBN을 변경하는 for 문을 작성해 보세요.
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
  void update_whole_isbn();

private:
  vector<book> book_list;
};

tuple<string, string, int, string> library::get_book_info(unsigned int index) {

  auto&& book = book_list[index];
  return make_tuple(book.title, book.author, book.publish_year, book.isbn);
}

void library::update_whole_isbn() {
  for (auto& book : book_list) {
    book.isbn = "C++" + book.isbn;
  }
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

  cout << "수정 전" << endl;
  for (int i = 0; i < 5; ++i) {
    print_book_list(book_manager, i);
  }

  book_manager.update_whole_isbn();

  cout << "수정 후" << endl;
  for (int i = 0; i < 5; ++i) {
    print_book_list(book_manager, i);
  }

  return 0;
}
```
###### 실행결과
```
수정 전
책 [0] - (내일을 향해 달리다., 홍길동, 2009, 00000001)
책 [1] - (바람과 함께 슁슁, 아무개, 2020, 00124001)
책 [2] - (성공하는 사람들의 7가지 속삭임, 유명인, 2019, 02528301)
책 [3] - (1980년대, 피터, 2022, 19224981)
책 [4] - (빅앤 스몰 브라더, 암자, 2024, 99128178)
수정 후
책 [0] - (내일을 향해 달리다., 홍길동, 2009, C++00000001)
책 [1] - (바람과 함께 슁슁, 아무개, 2020, C++00124001)
책 [2] - (성공하는 사람들의 7가지 속삭임, 유명인, 2019, C++02528301)
책 [3] - (1980년대, 피터, 2022, C++19224981)
책 [4] - (빅앤 스몰 브라더, 암자, 2024, C++99128178)
```
##### 설명
[문제 1]에서 ISBN을 갱신하는 update_whole_isbn() 함수를 추가 했습니다. 범위 기반 for문으로 책 객체를 레퍼런스로 받아 온 후 C++ 접두어를 추가 합니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

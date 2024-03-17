#### 문제 4 도서 목록 갱신
[문제 3]에서 만든 도서 목록을 갱신하고자 합니다. 먼저 클래스에 분류를 추가합니다. 분류는 ‘novel’, ‘fiction’, ‘non-fiction’, ‘sf’, ‘essay’이며, 유지·보수 편의를 위해 클래스 외부에서 열거형으로 정의해서 클래스 내부에서 정의한 것처럼 사용하고자 합니다. 분류 역시 클래스 멤버로 추가합니다.
<br/><br/>

---


#### 모범 답안
##### 답안
```cpp
#include <iostream>
#include <vector>
#include <compare>
#include <algorithm>
using namespace std;

class book {
public:
  enum class category { novel, fiction, non_fiction, sf, essay };
  book(string title_param, string author_param, unsigned int publish_year_param,
    unsigned int price_param, string isbn_param, unsigned int lent_count_param, category book_category_param)
    : title(title_param), author(author_param), publish_year(publish_year_param),
    price(price_param), isbn(isbn_param), lent_count(lent_count_param), book_category(book_category_param) {};
  weak_ordering operator<=>(const book& object) const;
  static string get_category_name(category category_name);

private:
  string title = "";
  string author = "";
  unsigned int publish_year = 1900;
  unsigned int price = 10000;
  string isbn = "";
  unsigned int lent_count = 0;
  category book_category = category::novel;

  friend class library;
};

string book::get_category_name(category category_name) {
  switch (category_name) {
  case category::novel:
    return "소설";
    break;
  case category::fiction:
    return "픽션";
    break;
  case category::non_fiction:
    return "난픽션";
    break;
  case category::sf:
    return "공상과학";
    break;
  case category::essay:
    return "수필";
    break;
  }

  return "";
}

weak_ordering get_ordering_result(strong_ordering compare_result) {
  if (compare_result < 0) {
    return weak_ordering::less;
  }

  if (compare_result > 0) {
    return weak_ordering::greater;
  }

  return weak_ordering::equivalent;
}

weak_ordering book::operator<=>(const book& object) const {
  auto compare_result = publish_year <=> object.publish_year;
  if (0 != compare_result) {
    return get_ordering_result(compare_result);
  }

  compare_result = isbn <=> object.isbn;
  if (0 != compare_result) {
    return get_ordering_result(compare_result);
  }

  compare_result = lent_count <=> object.lent_count;
  if (0 != compare_result) {
    return get_ordering_result(compare_result);
  }
  return weak_ordering::equivalent;
}

class library {
public:
  void initialize();
  tuple<string, string, int, string, string> get_book_info(unsigned int index);
  void sort_book();
private:
  vector<book> book_list;
};

void library::sort_book() {
  sort(book_list.begin(), book_list.end());
}

tuple<string, string, int, string, string> library::get_book_info(unsigned int index) {

  auto&& book = book_list[index];
  return make_tuple(book.title, book.author, book.publish_year, book.isbn, book::get_category_name(book.book_category));
}

void library::initialize() {
  book book1("빅앤 스몰 브라더", "암자", 2024, 14000, "99128178", 0, book::category::fiction);
  book_list.push_back(book1);
  book book2("바람과 함께 슁슁", "아무개", 2020, 18000, "00124001", 0, book::category::novel);
  book_list.push_back(book2);
  book book3("성공하는 사람들의 7가지 속삭임", "유명인", 2019, 25000, "02528301", 1, book::category::essay);
  book_list.push_back(book3);
  book book4("내일을 향해 달리다.", "홍길동", 2019, 15000, "00000001", 0, book::category::fiction);
  book_list.push_back(book4);
  book book5("1980년대", "피터", 2020, 10000, "19224981", 4, book::category::sf);
  book_list.push_back(book5);
}

void print_book_list(library& lib, unsigned int index) {
  auto [title, author, year, isbn, category] = lib.get_book_info(index);
  cout << "책 [" << index << "] - (" << title << ", " << author << ", " << year << ", " << isbn << ", " << category << ")" << endl;
}

int main()
{
  library book_manager;
  book_manager.initialize();

  cout << "정렬 전" << endl;
  for (int i = 0; i < 5; ++i) {
    print_book_list(book_manager, i);
  }

  book_manager.sort_book();

  cout << endl << "정렬 후" << endl;
  for (int i = 0; i < 5; ++i) {
    print_book_list(book_manager, i);
  }
  return 0;
}
```
###### 실행결과
```
정렬 전
책 [0] - (빅앤 스몰 브라더, 암자, 2024, 99128178, 픽션)
책 [1] - (바람과 함께 슁슁, 아무개, 2020, 00124001, 소설)
책 [2] - (성공하는 사람들의 7가지 속삭임, 유명인, 2019, 02528301, 수필)
책 [3] - (내일을 향해 달리다., 홍길동, 2019, 00000001, 픽션)
책 [4] - (1980년대, 피터, 2020, 19224981, 공상과학)

정렬 후
책 [0] - (내일을 향해 달리다., 홍길동, 2019, 00000001, 픽션)
책 [1] - (성공하는 사람들의 7가지 속삭임, 유명인, 2019, 02528301, 수필)
책 [2] - (바람과 함께 슁슁, 아무개, 2020, 00124001, 소설)
책 [3] - (1980년대, 피터, 2020, 19224981, 공상과학)
책 [4] - (빅앤 스몰 브라더, 암자, 2024, 99128178, 픽션)
```
##### 설명
[문제 3]의 book클래스에 enum class만 추가된 간단한 예제입니다. 출력을 위해 정보를 조회하는 함수가 일부 수정되었습니다. eumn은 string으로 직접 지정할 수 없어 분류를 string으로 변환하는 정적 함수가 추가 되었습니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

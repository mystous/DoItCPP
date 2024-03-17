#### 문제 3 도서 리스트
간단한 도서 관리 프로그램을 만들기 위해서 도서 목록을 std::vector로 구현했습니다. 컨테이너 내에 각 원소는 ‘책 제목’, ‘작가’, ‘출판 연도’, ‘정가’, ‘ISBN’, ‘대여 횟수’를 저장할 수 있는 도서 클래스 객체입니다. 또한 정렬을 위해 3방항 비교 연산자를 만들려고 합니다. 비교 기준은 1순위 출판 연도, 2순위 ISBN, 3순위 대여 횟수입니다. 오름차순으로 정렬하는 3방항 비교 연산자를 도서 클래스에 포함된 연산자로 오버로딩 해 보세요. 1순위가 같으면 2순위를 비교하고, 2순위가 같으면 3순위를 비교하고 1, 2, 3순위가 모두 같으면 약한 비교로 동등을 반환합니다.
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
  book(string title_param, string author_param, unsigned int publish_year_param, 
    unsigned int price_param, string isbn_param, unsigned int lent_count_param)
    : title(title_param), author(author_param), publish_year(publish_year_param), 
      price(price_param), isbn(isbn_param), lent_count(lent_count_param) {};
  weak_ordering operator<=>(const book& object) const;

private:
  string title = "";
  string author = "";
  unsigned int publish_year = 1900;
  unsigned int price = 10000;
  string isbn = "";
  unsigned int lent_count = 0;

  friend class library;
};

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
  tuple<string, string, int, string> get_book_info(unsigned int index);
  void sort_book();
private:
  vector<book> book_list;
};

void library::sort_book() {
  sort(book_list.begin(), book_list.end());
}

tuple<string, string, int, string> library::get_book_info(unsigned int index) {

  auto&& book = book_list[index];
  return make_tuple(book.title, book.author, book.publish_year, book.isbn);
}

void library::initialize() {
  book book1("빅앤 스몰 브라더", "암자", 2024, 14000, "99128178", 0);
  book_list.push_back(book1);
  book book2("바람과 함께 슁슁", "아무개", 2020, 18000, "00124001", 0);
  book_list.push_back(book2);
  book book3("성공하는 사람들의 7가지 속삭임", "유명인", 2019, 25000, "02528301", 1);
  book_list.push_back(book3);
  book book4("내일을 향해 달리다.", "홍길동", 2019, 15000, "00000001", 0);
  book_list.push_back(book4);
  book book5("1980년대", "피터", 2020, 10000, "19224981", 4);
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
책 [0] - (빅앤 스몰 브라더, 암자, 2024, 99128178)
책 [1] - (바람과 함께 슁슁, 아무개, 2020, 00124001)
책 [2] - (성공하는 사람들의 7가지 속삭임, 유명인, 2019, 02528301)
책 [3] - (내일을 향해 달리다., 홍길동, 2019, 00000001)
책 [4] - (1980년대, 피터, 2020, 19224981)

정렬 후
책 [0] - (내일을 향해 달리다., 홍길동, 2019, 00000001)
책 [1] - (성공하는 사람들의 7가지 속삭임, 유명인, 2019, 02528301)
책 [2] - (바람과 함께 슁슁, 아무개, 2020, 00124001)
책 [3] - (1980년대, 피터, 2020, 19224981)
책 [4] - (빅앤 스몰 브라더, 암자, 2024, 99128178)
```
* 정렬 비교를 위해서 15장 되새김 문제의 책 순서와 다르게 변경하였습니다.
##### 설명
book 클래스 내부엣 3방향 비교 연산자를 재정의 합니다. 문제에서 주어진 조건 순서로 차례로 3방향 비교 연산을 진행합니다. 비교의 대상인 데이터 형식이 모두 strong_ordering이므로 strong_ordering::equal이 아닌 경우 weak_ordering의 결과로 변환하여 반환합니다. 동일한 경우 다음 조건을 비교 합니다. 

3가지 조건이 모두 동일하면 weak_ordering::equivalent을 반환합니다. 책의 단일 조건을 직접 비교한 것이 아니라 여러가지 조건을 조합해서 비교했기 때문에 의미적으로 weak_ordering을 반환하는 것입니다.

[문제로 돌아 가기](README.md "문제로 돌아 가기")

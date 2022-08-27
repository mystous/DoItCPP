#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>

using namespace std;

const string manifesto_file("../manifesto_for_agile_software_development.txt");

int main() {
  ifstream manifesto(manifesto_file);
  string manifesto_text;

  if (!manifesto.is_open()) {
    return -1;
  }

  cout << "C로 시작해서 E나 N으로 끝나는 '문자열' 찾기(대소 구별 없음)" << endl;
  while (getline(manifesto, manifesto_text)) {
    regex reg("c[a-z]*[en]", regex::icase);

    auto matching_begin = sregex_iterator(manifesto_text.begin(), manifesto_text.end(), reg);
    auto matching_end = sregex_iterator();
    __int64 find_ressult_counts = distance(matching_begin, matching_end);

    if (find_ressult_counts <= 0) {
      continue;
    }

    cout << "[찾음: " << find_ressult_counts << "]  ";
    for (auto match_result = matching_begin; match_result != matching_end; ++match_result) {
      auto smatch_result = *match_result;
      cout << smatch_result.str() << " : ";
    }
    cout << endl;
  }

  return 0;
}
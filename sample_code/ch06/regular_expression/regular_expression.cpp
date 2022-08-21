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

  //cout << "C로 시작해서 E나 N으로 끝나는 '단어'가 포함한 문장 찾기(대소 구별 없음)" << endl;
  cout << "C로 시작해서 E나 N으로 끝나는 '문자열'이 포함한 문장 찾기(대소 구별 없음)" << endl;
  while (getline(manifesto, manifesto_text)) {
    //regex reg("\\sc[a-z]*[en]\\s", regex::icase);
    regex reg("c[a-z]*[en]", regex::icase);
    smatch match_results;
    if (regex_search(manifesto_text, match_results, reg)) {
      cout << "[찾음] : " << manifesto_text << " - " << match_results[0] << endl;
    }
  }
  return 0;
}
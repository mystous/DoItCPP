#include <iostream>
#include <regex>
#include <list>
#include <atlbase.h>

using namespace std;

int main() {

  list<wstring> names {L"No.1: ±èÃ¶¼ö", L"No.2: ¹Ú¿µÈñ", L"No.3: ÃÖÁø»ç", L"N/A: ±èÀÌ»Ý", L"Exp: ÇÏ´Ã"};
  USES_CONVERSION;

  for (auto&& name : names) {
    cout << CW2A(name.c_str()) << " >> ";

    wregex re(L"([°¡-ÆR])([°¡-ÆR])([°¡-ÆR]*)");
    wstring newstring = regex_replace(name, re, L"$1*$3");
    //wstring newstring = regex_replace(name, re, L"¾Æ¹«°³");

    cout << CW2A(newstring.c_str())<< endl;
  }

  return 0;
}
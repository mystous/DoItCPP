#include <iostream>

using namespace std;

int main() {
  cout << "short : " << sizeof(short) << " bytes" << endl;
  cout << "unsigned short : " << sizeof(unsigned short) << " bytes" << endl;
  cout << "int : " << sizeof(int) << " bytes" << endl;
  cout << "unsigned int : " << sizeof(unsigned int) << " bytes" << endl;
  cout << "__int8 : " << sizeof(__int8) << " bytes" << endl;     // MS 전용
  cout << "__int16 : " << sizeof(__int16) << " bytes" << endl;   // MS 전용
  cout << "__int32 : " << sizeof(__int32) << " bytes" << endl;   // MS 전용
  cout << "__int64 : " << sizeof(__int64) << " bytes" << endl;   // MS 전용
  cout << "long : " << sizeof(long) << " bytes" << endl;
  cout << "unsigned long : " << sizeof(unsigned long) << " bytes" << endl;
  cout << "long long : " << sizeof(long long) << " bytes" << endl;
  cout << "unsigned long long : " << sizeof(unsigned long long) << " bytes" << endl;

  return 0;
}

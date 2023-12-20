#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class file_reader_original {
public:
  static int read_header();
  static file_reader_original* get_reader_instance();
  virtual void read_contents() = 0;
};

int file_reader_original::read_header() {
  // v1.0 이라고 가정
  return 1;

  // v2.0 이라고 가정
  //return 2;
}

class file_reader_v0100 : public file_reader_original {
private:
  virtual void read_contents() override;
};

void file_reader_v0100::read_contents() {
  cout << "v1.0 파일 본문 읽기" << endl;
}

class file_reader_v0200 : public file_reader_original {
public:
  virtual void read_contents() override;
};

void file_reader_v0200::read_contents() {
  cout << "v2.0 파일 본문 읽기" << endl;
}


file_reader_original* file_reader_original::get_reader_instance() {
  file_reader_original* reader = nullptr;

  switch (file_reader_original::read_header()) {
  case 1:
    reader = new file_reader_v0100();
    break;
  case 2:
  default:
    reader = new file_reader_v0200();
    break;
  }

  return reader;
}



int main(void) {

  file_reader_original* reader = nullptr;

  reader = file_reader_original::get_reader_instance();
  if (nullptr != reader) {
    reader->read_contents();
    delete reader;
  }

  return 0;
}
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int main() {

  fs::current_path("..");
  fs::path path_obj(fs::current_path());
  
  cout << fs::canonical(path_obj) << " - 하위 디렉토리 및 파일" << endl;
  for (auto const & dir : fs::directory_iterator(path_obj)) {
    cout << dir.path().relative_path() << endl;
  }

  cout << endl << fs::canonical(path_obj) << " - 하위 디렉토리 순회" << endl;
  for (auto const& dir : fs::recursive_directory_iterator(path_obj)) {
    cout << dir.path().relative_path() << endl;
  }

  fs::space_info disk_info = fs::space(path_obj);
  cout << endl << "디스크 용량:" << disk_info.capacity << endl
    << "디스크 가용량:" << disk_info.available << endl;

  return 0;
}
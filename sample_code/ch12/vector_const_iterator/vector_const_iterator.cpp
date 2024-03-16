#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  vector<int>::const_iterator const_it = vec.cbegin();
  cout << *const_it << endl;

  ++const_it;
  cout << *const_it << endl;

  const_it = vec.cend();
  --const_it;
  cout << *const_it << endl;

  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;

  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);

  vector<int>::iterator it = vec.begin();
  cout << *it << endl;

  it++;
  cout << *it << endl;

  it++;
  cout << *it << endl;

  it++;
  cout << *it << endl;

  it++;
  cout << *it << endl;

  return 0;
}

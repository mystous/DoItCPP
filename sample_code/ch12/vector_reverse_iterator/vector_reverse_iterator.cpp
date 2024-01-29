#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;

  for (int i = 0; i < 3; i++)
    vec.push_back(i);

  for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
    cout << *it << endl;

  return 0;
}

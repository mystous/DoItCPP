#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare_pairs(const pair<int, string>& a, const pair<int, string>& b) {
  return a.first < b.first;
}

int main() {
  vector<pair<int, string>> pairs = {
    {5, "apple"},
    {2, "orange"},
    {5, "banana"},
    {3, "grape"}
  };

  // std::stable_sort를 사용하여 pair를 첫 번째 요소에 따라 안정 정렬
  stable_sort(pairs.begin(), pairs.end(), compare_pairs);

  // 정렬된 결과 출력
  for (vector<pair<int, string>>::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
    const pair<int, string>& pair = *it;
    cout << pair.first << ": " << pair.second << endl;
  }

  return 0;
}

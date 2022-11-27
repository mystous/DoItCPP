#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <execution>
#include <chrono>

using namespace std;
using namespace chrono;
const int vector_size = 50000000;
const int max_dis_range = 10000;

template<class execution_policy>
void sort_and_merge(execution_policy &&policy, string print_out_msg) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dis(0, max_dis_range);
  system_clock::time_point start_time, end_time;
  microseconds spending_time;

  vector<int> source_1, source_2;
  vector<int> result(2 * vector_size);

  for (int i = 0; i < vector_size; ++i) {
    source_1.push_back(dis(gen));
    source_2.push_back(dis(gen));
  }

  start_time = system_clock::now();
  sort(policy, source_1.begin(), source_1.end());
  sort(policy, source_2.begin(), source_2.end());

  merge(policy, source_1.begin(), source_1.end(), source_2.begin(), source_2.end(), result.begin());
  end_time = system_clock::now();
  spending_time = duration_cast<microseconds>(end_time - start_time);
  cout << print_out_msg << spending_time.count() << "μs" << endl;
}

int main() {
 
  sort_and_merge(execution::seq, "순차 처리 실행 시간: ");
  sort_and_merge(execution::par, "병렬 처리 실행 시간: ");
  sort_and_merge(execution::unseq, "벡터라이제이션 처리 실행 시간: ");
  sort_and_merge(execution::par_unseq, "병렬 처림 + 벡터라이제이션 처리 실행 시간: ");

  return 0;
}
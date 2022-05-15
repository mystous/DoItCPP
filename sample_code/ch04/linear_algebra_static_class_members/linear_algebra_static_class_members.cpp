#include <iostream>
#include <list>

using namespace std;

class vector {
public:
  vector(int size);
private:
  int vector_size;
  list<int> contents;
};

vector::vector(int size) : vector_size(size) {
  for (int i = 0; i < vector_size; ++i) {
    contents.push_back(0);
  }
}

class matrix {
public:
  matrix(int row, int col);
  ~matrix();
private:
  int row_count;
  int col_count;
  list<vector*> contents;
};

matrix::matrix(int row, int col) : row_count(row), col_count(col) {
  for (int i = 0; i < row_count; ++i) {
    vector* new_vector = new vector(col_count);
    contents.push_back(new_vector);
  }
}

matrix::~matrix() {
  for (auto item : contents) {
    delete item;
  }
}

class linear_algebra {
public:
  static void matrix_multiply(matrix& operand1, matrix& operand2);
  static void dot_product(vector& operand1, vector& operand2);

private:
  static void matrix_vector_multiply(matrix& operand1, vector& operand2);
};

void linear_algebra::matrix_multiply(matrix& operand1, matrix& operand2) {
  cout << "두개의 행렬곱을 계산 합니다." << endl;
}

void linear_algebra::matrix_vector_multiply(matrix& operand1, vector& operand2) {
  cout << "행렬과 벡터의 곱을 계산 합니다." << endl;
}

void linear_algebra::dot_product(vector& operand1, vector& operand2) {
  cout << "벡터의 내적을 계산 합니다." << endl;
}

void do_matrix_multiply(matrix& matrix_1, matrix& matrix_2) {
  linear_algebra::matrix_multiply(matrix_1, matrix_2);
}

void do_matrix_vector_multiply(matrix& matrix_1, vector& vector_1) {
  //linear_algebra::matrix_vector_multiply(matrix_1, vector_1); // 접근 지정자에 따라 접근할 수 없음
}

void do_vector_innerproduct(vector& vector_1, vector& vector_2) {
  linear_algebra::dot_product(vector_1, vector_2);
}

int main() {
  matrix matrix_1(10, 10), matrix_2(10, 10);
  vector vector_1(10), vector_2(10);

  do_matrix_multiply(matrix_1, matrix_2);
  do_matrix_vector_multiply(matrix_1, vector_2);
  do_vector_innerproduct(vector_1, vector_2);
  return 0;
}
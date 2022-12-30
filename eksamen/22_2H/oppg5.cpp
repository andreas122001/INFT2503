#include <iostream>
#include <thread>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
public:
  vector<vector<T>> m;

  Matrix() {}
  Matrix(const vector<vector<T>> &matrix_) {
    for (size_t row = 0; row < matrix_.size(); ++row) {
      m.emplace_back(vector<T>(matrix_[row].size()));
      for (size_t col = 0; col < matrix_[row].size(); ++col) {
        m[row][col] = matrix_[row][col];
      }
    }
  }

  // Matrix<T> operator[](const int index)

  void init(const int rows, const int cols) {
    m = vector<vector<T>>(rows);
    for (int i = 0; i < rows; ++i) {
      m[i] = vector<T>(cols);
    }
  }

  friend ostream &operator<<(ostream &stream, const Matrix<T> &matrix) {
    for (size_t row = 0; row < matrix.m.size(); ++row) {
      stream << "[ ";
      for (size_t col = 0; col < matrix.m[row].size(); ++col) {
        stream << matrix.m[row][col] << " ";
      }
      stream << "]" << endl;
    }
    return stream;
  }

  Matrix<T> operator*(const Matrix<T> &other) const {
    int rows = this->m.size();
    int cols = other.m[0].size();

    Matrix<T> res;
    res.init(rows, cols);
    vector<thread> threads;

    for (int row = 0; row < rows; ++row) {

      threads.emplace_back([row, cols, &res, this, &other] {
        for (int col = 0; col < cols; ++col) {
          for (size_t this_col = 0; this_col < other.m.size(); ++this_col) {
            res.m[row][col] += this->m[row][this_col] * other.m[this_col][col];
          }
        }
      });
    }

    for (auto &t : threads)
      t.join();

    return res;
  }
};

int main() {
  Matrix<int> m_a({{1, 2}, {3, 4}, {5, 6}});
  cout << m_a << endl;
}

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec) {
  stream << "{ ";

  if (!vec.empty()) {
    for (size_t i = 0; i < vec.size() - 1; ++i)
      stream << vec[i] << ", ";
    stream << vec[vec.size() - 1];
  }

  return stream << " }";
}

template <typename T>
vector<T> operator*(const vector<T> &vec, double mult) {
  vector<T> new_vec(vec.size(), 0);
  for (size_t i = 0; i < vec.size(); ++i) {
    new_vec[i] = vec[i] * mult;
  }
  return new_vec;
}

template <typename T, typename T2>
vector<T> operator*(const vector<T> &vec, const vector<T2> &vec2) {
  vector<T> new_vec(vec.size(), 0);
  for (size_t i = 0; i < vec.size(); ++i) {
    new_vec[i] = vec[i] * vec2[i];
  }
  return new_vec;
}

int main() {
  cout << std::vector<int>() << endl;
  cout << std::vector<float>({1.5, 2.5}) << endl;
  std::vector<int> vec = {1, 2, 3};
  cout << vec << endl;
  cout << vec * 3 << endl;
  cout << vec * vec << endl;
}

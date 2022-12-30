#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T1, typename T2>
vector<T2> map_f(const vector<T1> &vec, const function<T2(T1)> &func) {
  vector<T2> res(vec.size());
  for (size_t i = 0; i < vec.size(); ++i) {
    res[i] = func(vec[i]);
  }
  return res;
}

template <typename T>
ostream &operator<<(ostream &stream, const vector<T> &vec) {
  stream << "{ ";
  if (!vec.empty()) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
      stream << vec[i] << ", ";
    }
    stream << vec[vec.size() - 1] << " ";
  }
  return stream << "}";
}

int main() {
  cout << map_f<int, int>({1, 2, 3}, [](int a) { return a * 2; }) << endl;
  cout << map_f<float, float>({1, 2.3, 3}, [](float a) { return a / 2; }) << endl;
  cout << map_f<string, string>({"hello", "world"}, [](string s) { return s + "."; }) << endl;
  cout << map_f<string, int>({"hello", "world"}, [](string s) { return s.size(); }) << endl;
}

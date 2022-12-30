#include <iostream>
#include <vector>

using namespace std;

int times_two(int a) {
  return a * 2;
}

double times_two(double a) {
  return a * 2;
}

string times_two(string a) {
  return a + a;
}

vector<int> times_two(const vector<int> &vec) {
  vector<int> vec2(vec.size());
  for (size_t i = 0; i < vec.size(); ++i) {
    vec2[i] = vec[i] * 2;
  }
  return vec2;
}

ostream &operator<<(ostream &stream, const vector<int> &vec) {
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
  cout << times_two(2) << endl;
  cout << times_two(2.25) << endl;
  cout << times_two("test") << endl;
  cout << times_two(vector<int>{1, 2, 3}) << endl;
}

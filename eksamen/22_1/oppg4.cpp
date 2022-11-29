#include <functional>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

vector<int> parallell_transform(vector<int> &a, vector<int> &b, const function<int(int, int)> &func) {
  if (a.size() != b.size())
    return vector<int>();

  int thread_count = thread::hardware_concurrency();
  vector<thread> threads;
  vector<int> temp(a.size());

  for (int t = 0; t < thread_count; ++t)
    threads.emplace_back([&temp, t, thread_count, &a, &b, &func] {
      for (size_t i = t; i < a.size(); i += thread_count)
        temp[i] = func(a[i], b[i]);
    });

  for (auto &t : threads)
    t.join();

  return temp;
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
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> b = {2, 3, 4, 5, 6};
  cout << parallell_transform(a, b, [](int a_element, int b_element) {
    return a_element + b_element;
  }) << endl;
  cout << parallell_transform(a, b, [](int a_element, int b_element) {
    return a_element * b_element;
  }) << endl;
}

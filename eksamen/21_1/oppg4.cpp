#include <functional>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void parallell_transform(vector<int> &vec, int n_threads, function<int(int)> transform) {
  vector<thread> threads;

  for (int thread_i = 0; thread_i < n_threads; ++thread_i)
    threads.emplace_back([thread_i, n_threads, &vec, &transform]() {
      for (size_t i = thread_i; i < vec.size(); i += n_threads)
        vec[i] = transform(vec[i]);
    });

  for (auto &thread : threads)
    thread.join();
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  parallell_transform(vec, 4, [](int e) {
    return e * 2;
  });
  for (auto &e : vec)
    cout << e << endl;
}

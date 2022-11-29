#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Find {
public:
  function<bool(int)> eval;
  Find(function<int(int)> eval_) : eval(eval_) {}
  friend int *operator|(vector<int> &vec, const Find &finder) {
    for (auto &e : vec) {
      if (finder.eval(e))
        return &e;
    }
    return nullptr;
  }
};

class Reduce {
public:
  function<int(int, int)> func;
  int initial_value;
  Reduce(const function<int(int, int)> &func_, int init) : func(func_), initial_value(init) {}
  friend int operator|(vector<int> &vec, const Reduce &reduce) {
    int prev = reduce.initial_value;
    for (auto &e : vec) {
      prev = reduce.func(prev, e);
    }

    return prev;
  }
};

int main() {
  vector<int> vec = {1, 2, 3};
  cout << *(vec | Find([](int value) { return value > 1; })) << endl;
  cout << (vec | Find([](int value) { return value == 5; })) << endl;
  cout << (vec | Reduce(
                     [](int previous_value, int current_value) {
                       return previous_value + current_value;
                     },
                     0 /* initial value */))
       << endl;
  cout << (vec | Reduce(
                     [](int previous_value, int current_value) {
                       return previous_value + 2 * current_value;
                     },
                     5 /* initial value */))
       << endl;
}

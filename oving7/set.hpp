#pragma once
#include <iostream>
#include <vector>

class Set {
private:
public:
  std::vector<int> set;
  Set();
  Set(int *array);
  Set(std::vector<int> &vector);
  Set operator||(Set &other) const;
  void operator+=(int num);
  void operator+=(Set &other);
  void operator+=(std::vector<int> &vector);
  Set &operator=(Set &other);
  friend std::ostream &operator<<(std::ostream &os, const Set &set);
  void operator++(int) const;
};

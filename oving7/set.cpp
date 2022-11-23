#include "set.hpp"
#include <iostream>

Set::Set() {}
Set::Set(int *array) {
  for (size_t i = 0; i < sizeof array; i++)
    *this += array[i];
}

Set::Set(std::vector<int> &vector) {
  for (int elem : vector) {
    *this += elem;
  }
}

Set Set::operator||(Set &other) const {
  Set set = *this;
  set += other;
  return set;
}

void Set::operator+=(int num) {
  bool num_exists = false;
  for (auto elem : this->set) {
    if (elem == num)
      num_exists = true;
  }
  if (!num_exists)
    this->set.emplace_back(num);
  return;
}

void Set::operator+=(Set &other) {
  for (auto elem : other.set) {
    *this += elem;
  }
}

void Set::operator+=(std::vector<int> &vector) {
  for (auto elem : vector) {
    *this += elem;
  }
}

Set &Set::operator=(Set &other) {
  this->set = other.set;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Set &set) { // antar at med "print ut" menes dette (altså ikke-medlems-operator)
  os << "{ ";
  for (auto elem : set.set) {
    os << elem << " ";
  }
  return os << "}";
}

void Set::operator++(int) const { // la til denne i tillegg, men den gir ikke mye mening...
  std::cout << "{ ";
  for (auto elem : this->set) {
    std::cout << elem << " ";
  }
  std::cout << "}" << std::endl;
}

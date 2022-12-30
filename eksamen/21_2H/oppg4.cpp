#include <iostream>

using namespace std;

class Meter {
public:
  static const int multiplier = 1;
};

class Kilometer {
public:
  static const int multiplier = 1000;
};

template <typename T>
class Distance {
public:
  int m;

  Distance(int value) : m(value * T::multiplier) {}

  template <typename T2>
  Distance operator+(const Distance<T2> &other) {
    auto temp = *this;
    temp.m += other.m;
    return temp;
  }

  Distance operator+=(int val) {
    this->m += val * T::multiplier;
    return *this;
  }

  friend ostream &operator<<(ostream &stream, const Distance &dist) {
    return stream << dist.m << "m";
  }
};

int main() {
  Distance<Meter> meters(2);
  meters += 3;
  Distance<Kilometer> kilometers(2);
  kilometers += 3;
  cout << "5 meters: " << meters << endl;
  cout << "5 kilometers: " << kilometers << endl;
  cout << "5 kilometers + 5 meters: " << kilometers + meters << endl;
}

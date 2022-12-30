#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
class Angle {
public:
  constexpr static double pi = 3.14159265359;
  T value;
  Angle(int val) : value(val % 360) {}
  Angle(double val) : value(fmod(val, pi)) {}

  friend ostream &operator<<(ostream &stream, const Angle &angle) {
    return stream << angle.value;
  }

  // Angle operator+(T val) {
  //   return this->value + static_cast<T>(val);
  // }

  Angle operator+(int val) {
    return this->value + val;
  }

  Angle operator+(double val) {
    return this->value + val;
  }
};

int main() {
  cout << Angle<int>(30) << endl;
  cout << (Angle<int>(30) + 360) << endl;
  cout << (Angle<int>(30) + 3.14159265359) << endl;
  cout << Angle<double>(3.14159265359 / 2) << endl;
  cout << (Angle<double>(3.14159265359 / 2) + 3.14159265359) << endl;
  cout << (Angle<double>(3.14159265359 / 2) + 3) << endl;
}

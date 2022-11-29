#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
class Angle {
public:
  const double pi = 3.14159265359;
  T value;

  Angle(int val) : value(val % 360) {}
  Angle(double val) : value(fmod(val, pi)) {}

  friend ostream &operator<<(ostream &stream, const Angle &angle) {
    return stream << angle.value;
  }
};

int main() {
  Angle<int> angle1(30);
  cout << angle1 << endl;
  Angle<int> angle2(390);
  cout << angle2 << endl;
  Angle<double> angle3(3.14159265359 / 2);
  cout << angle3 << endl;
  Angle<double> angle4(3.14159265359 * 1.5);
  cout << angle4 << endl;
}

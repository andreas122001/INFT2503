#include <cmath>
#include <iostream>

template <typename T>
bool equals(T a, T b) {
  return a == b;
}

bool equals(double a, double b) {
  return std::abs(a - b) < 0.00001;
}

int main() {
  std::cout << "2 == 1: " << equals(2, 1) << std::endl;
  std::cout << "2 == 2: " << equals(2, 2) << std::endl;
  std::cout << "100023 == 100023: " << equals(100023, 100023) << std::endl;
  std::cout << "\"TEST\" == \"TEST\": " << equals("TEST", "TEST") << std::endl;
  std::cout << "\"TEST\" == \"FOO\": " << equals("TEST", "FOO") << std::endl;

  std::cout << "0.00001 == 0.0: " << equals(0.00001, 0.0) << std::endl;
  std::cout << "0.000001 == 0.0: " << equals(0.000001, 0.0) << std::endl;
  std::cout << "5.00000123231 == 5.00000991223: " << equals(5.00000123231, 5.00000991223) << std::endl;
  std::cout << "5.0000123231 == 5.0000991223: " << equals(5.0000123231, 5.0000991223) << std::endl;
}

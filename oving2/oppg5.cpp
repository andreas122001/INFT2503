#include <iostream>

using namespace std;

int main() {
  double number;
  double *p = &number;
  double &ref = number;

  number = 5;
  *p = 5;
  ref = 5;

  cout << number << endl
       << *p << endl
       << ref << endl;
}

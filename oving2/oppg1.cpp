#include <iostream>

using namespace std;

int main() {
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << "i = " << i << ", &i = " << &i << endl;
  cout << "j = " << j << ", &j = " << &j << endl;
  cout << "p = " << p << ", &p = " << &p << endl;
  cout << "q = " << q << ", &q = " << &q << endl;

  // Output:
  // i = 3, &i = 0x7a0a3ffcec
  // j = 5, &j = 0x7a0a3ffce8
  // p = 0x7a0a3ffcec, &p = 0x7a0a3ffce0
  // q = 0x7a0a3ffce8, &q = 0x7a0a3ffcd8

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;
  cout << *p << " " << *q << endl;

  // Output:
  // 8 8
}

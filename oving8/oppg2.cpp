#include <iostream>

using namespace std;

template <typename A, typename B>
class Pair {
public:
  A first;
  B second;
  Pair(A a, B b) : first(a), second(b) {}
  Pair operator+(Pair &other) const {
    Pair pair(this->first + other.first, this->second + other.second);
    return pair;
  }
  bool operator>(Pair &other) const { // forutsetter at typene A og B kan adderes, eller at det fins spesialfunksjoner for >
    return this->first + this->second > other.first + other.second;
  }
};
/*
 * Antar at kompilatoren velger riktig versjon av operatorene + og > basert hvilken type som brukes
 * (sjekker de spesielle/typespesifikke versjonene først).
 */
int main() {
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

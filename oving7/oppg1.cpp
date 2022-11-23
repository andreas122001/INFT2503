#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction fraction1(1, 2);
  Fraction fraction2(1, 3);

  cout << fraction1 - 5 << endl;
  cout << 5 - fraction1 << endl;

  cout << 5 - 3 - fraction1 - 7 - fraction2 << endl;

  /* oppg1, b)
   * Venstreassosiativt:
   * Fraction::operator-( Fraction::operator-( (friend)Fraction::operator-( int::operator-(5,3), fraction1 ), 7 ), fraction2)
   * (((5-3) - fraction) - 7) - fraction2
   * Først regnes (int-int -> int) ut, så (int-fraction1 -> Fraction), så (Fraction-int -> Fraction), til slutt (Fraction-Fraction -> Fraction)
   * Vi bruker altså alle versjonene av operator-()-funksjonen som har med Fraction-klassen å gjøre (+ (int-int)).
   * */
}

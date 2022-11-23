#include <iostream>

int main() {
  int a = 5;
  int &b = a; // en referanse må referere til noe - kan ikke være tom.
  int *c;
  c = &b;
  a = b + *c; // a og b er ikke en pekere, og kan derfor ikke peke på noen verdi.
  b = 2;      // kan ikke sette adressen til b lik 2, siden 2 er et tall og ikke en adresse. I tillegg kan man ikke re-referere en referanse.
}

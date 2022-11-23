#include <iostream>

using namespace std;

int main() {
  const int length = 5;

  cout << "Du skal skrive inn " << length << " temperaturer." << endl;

  double temp;
  int interval1 = 0;
  int interval2 = 0;
  int interval3 = 0;

  for (int i = 1; i < length + 1; i++) {
    cout << "Temperatur nr " << i << ": ";
    cin >> temp;
    if (temp < 10)
      interval1++;
    else if (temp >= 10 && temp <= 20)
      interval2++;
    else if (temp > 20)
      interval3++;
  }

  cout << "Antall under 10 er " << interval1 << endl;
  cout << "Antall mellom 10 og 20 er " << interval2 << endl;
  cout << "Antall over 20 er " << interval3 << endl;
}

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
  const int length = 5;
  const string filename = "temperatures";
  double temperatures[length];

  read_temperatures(temperatures, length);

  double temp;
  int interval1 = 0;
  int interval2 = 0;
  int interval3 = 0;
  for (int i = 0; i < length; i++) {
    temp = temperatures[i];
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

void read_temperatures(double temperatures[], int length) {
  const char filename[] = "temperatures";
  cout << "Reading " << length << " temperatures from file '" << filename << "'." << endl;

  ifstream file;
  file.open(filename);

  if (!file) {
    cout << "Well, that didn't work... Error reading file?" << endl;
    exit(EXIT_FAILURE);
  }

  double temp;
  for (int i = 0; i < length; i++) {
    file >> temp;
    temperatures[i] = temp;
  }
}

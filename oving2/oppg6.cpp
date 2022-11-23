#include <iostream>

using namespace std;

int find_sum(const int *table, int length);
void fill_increment(int *table, int length);

int main() {
  int length = 20;
  int table[length];

  fill_increment(table, length);

  int a = find_sum(table, 10);
  int b = find_sum(&table[10], 5);
  int c = find_sum(&table[length - 5], 5);

  cout << "Sum [1, 10]: " << a << endl
       << "Sum [11,15]: " << b << endl
       << "Sum [16, 20]: " << c << endl;
}

int find_sum(const int *table, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += *table; // eller: sum += table[i]; uten: table++;
    table++;
  }
  return sum;
}

void fill_increment(int *table, int length) {
  for (int i = 0; i < length; i++) {
    table[i] = i + 1;
  }
}

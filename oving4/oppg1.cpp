#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<double> vector;
  vector.emplace_back(1.0);
  vector.emplace_back(1.5);
  vector.emplace_back(2.0);
  vector.emplace_back(2.5);
  vector.emplace_back(3.0);

  cout << vector.front() << endl;
  cout << vector.back() << endl;

  vector.emplace(vector.begin() + 1, 1.25);

  cout << vector.front() << endl;        // første element
  cout << *(vector.begin() + 1) << endl; // (nye) andre element

  double guess;
  cout << "Sjekk om et tall er i lista: ";
  cin >> guess;

  auto p = find(vector.begin(), vector.end(), guess);
  auto answer = p != vector.end() ? "Tallet finnes!" : "Tallet finnes ikke...";
  cout << answer
       << endl;
  if (p != vector.end())
    cout << *p << endl;
}

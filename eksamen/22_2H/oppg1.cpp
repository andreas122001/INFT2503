#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string concat(const string &a, const string &b) {
  return a + b;
}

string concat(const int &a, const int &b) {
  return to_string(a) + to_string(b);
}

string concat(const vector<string> &vec) {
  stringstream stream;
  for (auto &e : vec)
    stream << e;
  return stream.str();
}

int main() {
  cout << concat("hello", "world") << endl;
  cout << concat(1, 2) << endl;
  cout << concat({"a", "b", "c"}) << endl;
}

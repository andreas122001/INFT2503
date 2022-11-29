#include <iostream>

using namespace std;

bool starts_with(const string &s1, const string &s2) {
  if (s2.size() > s1.size())
    return false;
  for (size_t i = 0; i < s2.size(); ++i)
    if (s1[i] != s2[i])
      return false;

  return true;
}

int main() {
  cout << starts_with("", "") << endl;
  cout << starts_with(string(""), "") << endl;
  cout << starts_with("This is a test", "This") << endl;
  cout << starts_with(string("This is a test"), "This") << endl;
  cout << starts_with("This is a test", "Test") << endl;
  cout << starts_with(string("This is a test"), "Test") << endl;
  cout << starts_with("This", "This is a test") << endl;
  cout << starts_with(string("This"), "This is a test") << endl;
}

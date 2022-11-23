#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main() {
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  cout << "v1: " << v1 << endl;

  vector<int> v2 = {2, 3, 12, 14, 24};
  cout << "v2: " << v2 << endl;

  // find_if
  auto pos = find_if(v1.begin(), v1.end(), [](int i) {
    return i > 15;
  });
  int index = pos - v1.begin();
  cout << "First element over 15 (in v1): " << v1[index] << " at index " << index << endl;

  // equals
  bool eq = equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int i, int j) {
    return abs(i - j) <= 2;
  });
  cout << "First 5 elements of v1 are within 2 of v2's elements: " << (eq ? "true" : "false") << endl;

  eq = equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int i, int j) {
    return abs(i - j) <= 2;
  });
  cout << "First 4 elements of v1 are within 2 of v2's elements: " << (eq ? "true" : "false") << endl;

  // replace_copy_if
  vector<int> result;
  result.resize(v1.size());
  auto end = replace_copy_if(
      v1.begin(), v1.end(), result.begin(), [](int i) {
        return i % 2 == 1;
      },
      100);
  result.erase(end, result.end());

  cout << "Odd numbers in v1 replaced with 100: " << result << endl;
}

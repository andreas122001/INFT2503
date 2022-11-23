#include "set.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {1, 4, 6, 10};

  Set set1;
  set1 += 2;
  set1 += 2; // set1 = {2}

  Set set2 = set1;
  set2 += 5;
  set2 += 3; // set2 = {2,5,3}

  set1 += 4; // set1 = {2,4}

  Set set3(v); // set2 = {1, 4, 6, 10}

  cout << set1 << endl;
  cout << set2 << endl;
  cout << (set1 || set2) << endl;
  cout << (set3 || set2 || set1) << endl;
}

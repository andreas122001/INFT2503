#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // a)
  string word1;
  string word2;
  string word3;

  cin >> word1;
  cin >> word2;
  cin >> word3;

  // b)
  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << "sentence = " << sentence << endl;

  // c)
  cout << "word1.length() -> " << word1.length()
       << "\nword2.length() -> " << word2.length()
       << "\nword3.length() -> " << word3.length()
       << "\nsentence.length() -> " << sentence.length()
       << endl;

  // d)
  string sentence2 = sentence;
  cout << "sentence2 = " << sentence2 << endl;

  // e)
  if (sentence2.length() > 12) {
    sentence2.replace(10, 3, "XX");
    cout << "sentence2 = " << sentence2
         << "\nsentence = " << sentence << endl;
  } else {
    cout << "'sentence2' er ikke lang nok...";
  }

  // f)
  string sentence_start = sentence.substr(0, (5 < sentence.length()) ? 5 : sentence.length());
  cout << "sentence_start = " << sentence_start
       << "\nsentence = " << sentence << endl;

  // g)
  cout << "Contains 'hello' = " << ((sentence.find("hello") != string::npos) ? "true" : "false") << endl;

  // h)
  int count = 0;
  string::size_type pos = 0;
  while ((pos = sentence.find("er", pos)) != string::npos) {
    count++;
    pos++;
  }

  cout << "Occurrences of 'er': " << count << endl;

  return 0;
}

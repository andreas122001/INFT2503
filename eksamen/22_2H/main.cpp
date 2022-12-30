#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &stream, const vector<vector<string>> &result) {
  stream << std::right << std::setw(12) << "Name"
         << std::right << std::setw(12) << "avg"
         << std::right << std::setw(12) << "std"
         << endl;
  for (size_t i = 0; i < result.size(); ++i) {
    for (size_t j = 0; j < result[i].size(); ++j) {
      stream << std::right << std::setw(12) << result[i][j] << " ";
    }
    stream << endl;
  }
  return stream;
}

double average(const vector<double> &arr) {
  double sum = 0;
  for (auto &e : arr)
    sum += e;
  return sum / arr.size();
}

double std_1(const vector<double> &arr) {
  double avg = average(arr);
  double sum = 0;
  for (auto &e : arr)
    sum += pow(avg - e, 2);
  return sqrt(sum / arr.size());
  return sum;
}

vector<vector<string>> get_avg_and_std(const vector<string> &names, const vector<double> values) {
  vector<vector<string>> result;
  if (names.size() != values.size())
    return result;

  // Construct a set of the names (unique names):
  vector<string> unique_names;
  for (auto &name : names) {
    bool is_unique = true;
    for (auto &u_name : unique_names) { // enumerate current unique_names
      if (u_name == name) {             // if found, name is not unique
        is_unique = false;
      }
    }
    if (is_unique) // if not found, add to unique_names
      unique_names.emplace_back(name);
  }

  vector<double> avg(unique_names.size()); // initialize avg-array
  vector<double> std(unique_names.size()); // initialize std-array

  for (size_t i = 0; i < unique_names.size(); ++i) {
    vector<double> c_values; // initialize values for given character
    for (size_t j = 0; j < names.size(); ++j) {
      if (names[j] == unique_names[i]) {
        c_values.emplace_back(values[j]);
      }
    }
    // Calculate avg and std and add to arrays
    avg[i] = average(c_values);
    std[i] = std_1(c_values);
  }

  for (size_t i = 0; i < unique_names.size(); ++i) {
    vector<string> strings = {unique_names[i], to_string(avg[i]), to_string(std[i])};
    result.emplace_back(strings);
  }

  return result;
}

int main() {
  vector<string> names = {"A", "A", "A", "B", "C", "D", "D", "E"};
  vector<double> values = {10, 12, 10, 13, 16, 20, 23, 15};

  vector<vector<string>> result;
  result = get_avg_and_std(names, values);

  cout << result << endl;
}

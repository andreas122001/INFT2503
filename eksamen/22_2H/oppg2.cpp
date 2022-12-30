#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Animal {
public:
  virtual ~Animal() {}
  virtual string makeNoise() const = 0;
};

class Elephant : public Animal {
public:
  string makeNoise() const override {
    return "Toot!";
  }
};

class Pig : public Animal {
public:
  string makeNoise() const override {
    return "Honk!";
  }
};

int main() {
  vector<unique_ptr<Animal>> animals;
  animals.emplace_back(make_unique<Elephant>());
  animals.emplace_back(make_unique<Elephant>());
  animals.emplace_back(make_unique<Pig>());

  for (auto &a : animals)
    cout << a->makeNoise() << endl;
}

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Animal {
public:
  virtual ~Animal() {}
  virtual string produce() = 0;
};

class Chicken : public Animal {
public:
  Chicken() {}
  string produce() override {
    return "egg";
  }
};

class Sheep : public Animal {
public:
  Sheep() {}
  string produce() override {
    return "wool";
  }
};

class Cow : public Animal {
public:
  Cow() {}
  string produce() override {
    return "milk";
  }
};

class Farm {
public:
  Farm() {}
  void add_animal(const string &name) {
    if (name == "chicken")
      animals.emplace_back(make_unique<Chicken>());
    else if (name == "cow")
      animals.emplace_back(make_unique<Cow>());
    else if (name == "sheep")
      animals.emplace_back(make_unique<Sheep>());
  }
  vector<unique_ptr<Animal>> animals;
};

int main() {
  Farm farm;
  farm.add_animal("chicken");
  farm.add_animal("chicken");
  farm.add_animal("chicken");
  farm.add_animal("cow");
  farm.add_animal("sheep");
  farm.add_animal("sheep");
  cout << "Farm production: " << endl;
  for (auto &animal : farm.animals)
    cout << animal->produce() << endl;
}

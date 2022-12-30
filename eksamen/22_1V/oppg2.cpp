#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Builder {
public:
  virtual ~Builder() {}
  virtual string build() const = 0;
};

class CMake : public Builder {
  string build() const override {
    return "cmake --build .";
  }
};

class Meson : public Builder {
  string build() const override {
    return "meson compile -C .";
  }
};

class Cargo : public Builder {
  string build() const override {
    return "cargo build";
  }
};

class ProgrammingLanguage {
  unique_ptr<Builder> builder;

public:
  ProgrammingLanguage() {}
  ProgrammingLanguage(unique_ptr<Builder> builder_) : builder(move(builder_)) {}
  virtual ~ProgrammingLanguage() {}
  virtual string print_line(const string &line) const = 0;
  virtual string for_each(const string &e, const string &vec) const = 0;

  string build() {
    if (builder)
      return builder->build();
    return "no builder";
  }
};

class Cpp : public ProgrammingLanguage {
public:
  Cpp() {}
  Cpp(unique_ptr<Builder> builder_) : ProgrammingLanguage(move(builder_)) {}
  string print_line(const string &line) const override {
    return "cout << \"" + line + "\" << endl;";
  }
  string for_each(const string &e, const string &vec) const override {
    return "for (auto &" + e + " : " + vec + ") {}";
  }
};

class Rust : public ProgrammingLanguage {
public:
  Rust() {}
  Rust(unique_ptr<Builder> builder_) : ProgrammingLanguage(move(builder_)) {}
  string print_line(const string &line) const override {
    return "println!(\"" + line + "\");";
  }
  string for_each(const string &e, const string &vec) const override {
    return "for " + e + " in &" + vec + " {}";
  }
};

int main() {
  vector<unique_ptr<ProgrammingLanguage>> programming_languages;
  programming_languages.emplace_back(make_unique<Cpp>());
  programming_languages.emplace_back(make_unique<Rust>());
  for (auto &programming_language : programming_languages) {
    cout << programming_language->print_line("Hello World") << endl;
    cout << programming_language->for_each("e", "vec") << endl
         << endl;
  }
  programming_languages.emplace_back(make_unique<Cpp>(make_unique<CMake>()));
  programming_languages.emplace_back(make_unique<Cpp>(make_unique<Meson>()));
  programming_languages.emplace_back(make_unique<Rust>(make_unique<Cargo>()));
  for (auto &programming_language : programming_languages) {
    cout << programming_language->build() << endl;
  }
}

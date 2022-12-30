#include <functional>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Button {
public:
  virtual ~Button() {}
  Button(const string &label_, const function<void()> on_click_) : label(label_), on_click(move(on_click_)) {}
  string label;
  function<void()> on_click;
  virtual void activate() {
    if (on_click) {
      on_click();
    }
  }
  virtual string toString() const {
    return "Button, label: " + label;
  };
  friend ostream &operator<<(ostream &stream, const Button &button) {
    return stream << button.toString();
  }
};

class ToggleButton : public Button {
public:
  bool active;
  ToggleButton(const string &label_, bool active_, const function<void()> on_click_) : Button(label_, move(on_click_)), active(active_) {}
  void activate() override {
    active = !active;
    Button::activate();
  }
  string toString() const override {
    return "ToggleButton, label: " + label + ", value: " + (active ? "toggled" : "not toggled");
  }
};

class LinkButton : public Button {
public:
  string link;
  LinkButton(const string &label_, const string &link_, const function<void()> on_click_) : Button(label_, move(on_click_)), link(link_) {}

  string toString() const override {
    return "LinkButton, label: " + label + ", link: " + link;
  }
};

int main() {
  std::vector<std::unique_ptr<Button>> buttons;
  buttons.emplace_back(std::make_unique<ToggleButton>("Toggle something", true, [] {
    cout << "Toggled something" << endl;
  }));

  buttons.emplace_back(std::make_unique<LinkButton>("Link to somewhere", "https://ntnu.no", [] {
    cout << "Opened link" << endl;
  }));

  for (auto &button : buttons) {
    cout << *button << endl;
    button->activate();
    cout << *button << endl;
  }
}

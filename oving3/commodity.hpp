#pragma once

#include <string>

using namespace std;

// const double tax = 1.99;

class Commodity {
public:
  Commodity(const string &name_, int id_, double price_);

  const string &get_name() const;
  int get_id() const;
  double get_price() const;
  double get_price(const double quantity) const;
  double get_price_with_sales_tax() const;
  double get_price_with_sales_tax(const double quantity) const;
  void set_price(double price);

private:
  string name;
  int id;
  double price;
};

const double pi = 3.141592;

class Circle {
public:
  Circle(double radius_);  // liten bokstav
  double get_area() const; // vil helst ha double kanskje
  double get_circumference() const;

private: // manglet kolon
  double radius;
};

Circle::Circle(double radius_) : radius(radius_) {} // fjernet 'public' og underscore på radius(), la til underscore på parameteren 'radius_'

double Circle::get_area() const { // la til 'const'
  return pi * radius * radius;
}

double Circle::get_circumference() const {  // la til typedeklarasjon
  double circumference = 2.0 * pi * radius; // la til typedeklarasjon
  return circumference;
}

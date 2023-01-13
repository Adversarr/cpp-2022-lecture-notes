#include <iostream>
#include <string>
using namespace std;

class Commodity {
public:
  Commodity() {}

  Commodity(double price, std::string name, int factory_id, unsigned int count):
    price_(price), name_(name), factory_id_(factory_id), count_(count) {}

  virtual void Print() const {
    std::cout << "Commodity:" << std::endl;
    std::cout << "\t1. price      = " << price_ << std::endl;
    std::cout << "\t2. name       = " << name_ << std::endl;
    std::cout << "\t3. factory_id = " << factory_id_ << std::endl;
    std::cout << "\t4. count      = " << count_ << std::endl;
  }

private:
  double price_;
  std::string name_;
  int factory_id_;
  unsigned int count_;
};

class HomeAppliance : public Commodity {
public:
  HomeAppliance() {}

  HomeAppliance(std::string color, unsigned int power, double price,
                std::string name, int factory_id, unsigned int count)
      : Commodity(price, name, factory_id, count), color_(color),
        power_(power) {}

  virtual void Print() const override {
    Commodity::Print();
    std::cout << "HomeAppliance:" << std::endl;
    std::cout << "\t1. color = " << color_ << std::endl;
    std::cout << "\t2. power = " << power_ << std::endl;
  }

private:
  std::string color_;
  unsigned int power_;
};

class Fridge : public HomeAppliance {
public:
  Fridge() {}

  Fridge(
      double length, std::string kind,
      std::string color, unsigned int power, double price, std::string name,
         int factory_id, unsigned int count)
      : HomeAppliance(color, power,price, name, factory_id, count), 
      length_(length), kind_(kind){}

  virtual void Print() const override {
    HomeAppliance::Print();
    std::cout << "Fridge:" << std::endl;
    std::cout << "\t1. length = " << length_ << std::endl;
    std::cout << "\t2. kind   = " << kind_ << std::endl;
  }

private:
  double length_;

  std::string kind_;
};

int main() { 
  Fridge fg(10, "Simple", "Red", 600, 3000, "Demo Fridge", 0, 300);
  fg.Print();
  return 0; }

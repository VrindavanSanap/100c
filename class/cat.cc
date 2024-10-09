#include <iostream>
#include <string>

using namespace std;


class Cat{
  private:
    string name;
    string color;
    string fav_toy;
  public:
    void print_cat(){
      cout << "My name is " << name;
      cout << " I am " << color << " cat";
      cout << ", My favourite toy is " << fav_toy;
    }

  Cat(){
    name = "Unknown";
    color = "Unknown";
    fav_toy = "Unknown";
  }

  Cat(string name_){
    name = name_;
    color = "Unknown";
    fav_toy = "Unknown";
  }

  Cat(string name_, string color_, string fav_toy_){
    name = name_;
    color = color_;
    fav_toy = fav_toy_;
  }




};

int main(){
  Cat cat1;
  cout << "Cat 1.." << endl;
  cat1.print_cat();
  cout << endl;

  Cat cat2("Hobbi");
  cout << "Cat 2.." << endl;
  cat2.print_cat();
  cout << endl;

  Cat cat3("Trashy", "orange", "ball of yarn");
  cout << "Cat 3.." << endl;
  cat3.print_cat();
  cout << endl;



  return 0;
}

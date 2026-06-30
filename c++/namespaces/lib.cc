#include <iostream>
namespace lib {
int value = 42;
void print_value() { std::cout << "value: " << value << std::endl; }
}  // namespace lib

int main() {
  lib::print_value();

  using namespace lib;  // using directive
  std::cout << value << std::endl;
  using std::cout;  /// using declaration
  cout << "hello!" << std::endl;
}

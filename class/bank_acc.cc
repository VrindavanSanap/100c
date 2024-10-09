#include <iostream>
#include <string>

using namespace std;

class bank_account {
 public:
  string name;
  int balance;
  void desc();
};
void bank_account::desc(){
  cout << name << " has $" << balance<<"." << endl;
}

int main() { bank_account acc1;
  acc1.name = "Bob";
  acc1.balance = 3000;
  acc1.desc();
  return 0;
}

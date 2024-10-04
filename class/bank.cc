#include <iostream>
#include <string>

using namespace std;

class bank_account {
 public:
  string name;
  int balance;
	
};
int main() { bank_account acc1;
  acc1.name = "Bob";
  acc1.balance = 3000;

  return 0;
}

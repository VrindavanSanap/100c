#include <iostream>
#include <set>

using namespace std;

int main(){
  
  set<int> set1{1,2,3,4,5};

  set1.insert(42);
  cout<< set1.count(4)<<endl;

  for (auto elm:set1){
    cout <<elm<<endl;
  }

}

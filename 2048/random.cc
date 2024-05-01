#include <iostream>
#include <random>

int main() {
    // Create a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9); // Define the range
    int fours = 0;
    int twos = 0;
    for (int i =0 ;i < 1000;i++){
        int random_int = dis(gen);
        if (random_int < 1){
          fours++; 
        }else{
          twos++;
        }
    }
    std::cout<<"Twos-"<<twos<<" Fours-"<<fours<<std::endl;
    return 0;
}


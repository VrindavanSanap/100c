#include <iostream>
#include <string>

#include <vector>
using namespace std;

struct Card{
  string suit;
  string rank;
  
  Card(string suit_, string rank_){
    suit = suit_;
    rank = rank_;

  }

};

const vector<string> SUITS{"spades", "diamonds", "clubs", "hearts"};

const vector<string> RANKS{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
vector<Card> CARDS;    


class poker_deck{
  vector<Card> _cards;    
  public:
    poker_deck(){
      _cards = CARDS;
   }
  
  void print_all_cards(){
    for (std::size_t i = 0; i < _cards.size(); i++) {
      cout << "Card(rank='" << _cards[i].rank <<"',";
      cout << " suit='"<< _cards[i].suit<< "')\n";
    }
  }

  vector<Card> draw_poker_hand(){
    



  }


};

int main(){
  for (const auto& suit_i : SUITS) {
    for (const auto& rank_i : RANKS) {
      CARDS.push_back(Card(suit_i, rank_i));
    }
  }
  poker_deck my_deck;
  my_deck.print_all_cards();
  
  return 0;
}

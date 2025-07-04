#include "Deck.h"
#include "Card.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

  Deck d1;
  Card p1;
  Card p2;

  d1.newDeck();
  cout << "Deck size: " << d1.deckSize() << endl;

  p1 = d1.dealCard();
  p2 = d1.dealCard();
  p1.printCard();
  p2.printCard();

  cout << "Deck size: " << d1.deckSize() << endl;

  return 0;

}

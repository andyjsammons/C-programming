#ifndef DECK_H
#define DECK_H

#include "Card.h"


#include <vector>
using namespace std;


class Deck{
private:
  vector<Card> mydeck;
public:
  int deckSize();
  void newDeck();
  Card dealCard();
};


#endif

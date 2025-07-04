#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

using namespace std;


class Card{
private:
  string name;
  string suit;
  int value;

public:
  void setName(string cardName);
  void setSuit(string cardSuit);
  void setValue(int cardValue);
  string getName();
  string getSuit();
  int getValue();
  void printCard();

  Card();
  Card(string cardName, string cardSuit, int cardValue);

};

#endif

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Deck::deckSize(){
  return mydeck.size();
}

void Deck::newDeck(){
	
	srand(time(NULL));
	Card newCard;
	vector<string> theseSuits = {"Spades", "Hearts","Clubs","Diamonds"};
	vector<string> royals = {"Queen", "Jack", "King","Ace"};
	vector<string> casuals = {"Two", "Three", "Four", "Five", "Six", "Seven","Eight","Nine","Ten"};

	for ( int i = 0; i < 4; i++){
		for ( int j = 0; j < 13;j++){

			if (j+1 == 1){
				newCard = Card(royals.at(3), theseSuits.at(i), 11);
			}
			else if (j < 10){
				newCard = Card(casuals.at(j-1), theseSuits.at(i), j + 1);
			}
			else if (j == 10){
				newCard = Card(royals.at(1), theseSuits.at(i), 10);
			}
			else if (j == 11){
				newCard = Card(royals.at(0),theseSuits.at(i),10);
			}
			else if (j == 12){
				newCard = Card(royals.at(2), theseSuits.at(i),10);
			}
		mydeck.push_back(newCard);
		
		}
	}
	for (int i = 51; i >= 0; i--){
		Card temp = mydeck.at(i);
		int index = rand() % 52;
		mydeck.at(i) = mydeck.at(index);
		mydeck.at(index) = temp;
	}
}

Card Deck::dealCard(){
	Card top = *mydeck.begin();
	mydeck.erase(mydeck.begin());
	return top;
}

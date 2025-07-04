#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include <fstream>
#include <iomanip>

using namespace std;

void play(double *playerMoney){
	
	ofstream myfile;
	myfile.open("blackjackresults.txt",ios::app);
	Deck deck;
	vector<Card> playerCards;
	vector<Card> dealerCards;
	//double playerMon = *playerMoney;
	double bet = 9999999;
	double dealerMoney;
	int dealerTotal = 0;
	int playerTotal = 0;
	char yorn = 'y';
	
	while (bet > *playerMoney){
		cout << "Your money: " << "$" << setprecision(2) << fixed << *playerMoney << endl;
		cout << "How much money would you like to bet? (ex. 500.00)"<< endl;
		cin >> bet;
		
	
		cin.ignore();
	}
	
	deck.newDeck();
	int index = 0;
	while (yorn == 'y'){
		if (deck.deckSize() < 21){
			deck.newDeck();
		}
		if (playerCards.size() == 0 && dealerCards.size() == 0){
			playerCards.push_back(deck.dealCard());
			playerTotal += playerCards.at(0).getValue();
			dealerCards.push_back(deck.dealCard());
			dealerTotal += dealerCards.at(0).getValue();
			playerCards.push_back(deck.dealCard());
			playerTotal += playerCards.at(1).getValue();
			dealerCards.push_back(deck.dealCard());
			dealerTotal += dealerCards.at(1).getValue();
			
			if ((playerCards.at(0).getName() == "Jack" && playerCards.at(1).getName() == "Ace")  || (playerCards.at(1).getName() == "Jack" && playerCards.at(0).getName() == "Ace")){
			myfile<<"BLACKJACK"<<endl;
			}
			
			if ((dealerCards.at(0).getName() == "Jack" && dealerCards.at(1).getName() == "Ace")  || (dealerCards.at(1).getName() == "Jack" && dealerCards.at(0).getName() == "Ace")){
			myfile<<"BLACKJACK"<<endl;
			}
		}
		cout << "Dealer's Cards: " << endl;
		cout << "________________" << endl;
		cout << endl;
		dealerCards.at(0).printCard();
		
		cout << endl;
		
		cout << "Your cards: " << endl;
		cout << "________________" << endl;
		cout << endl;
		for (int i = 0; i < playerCards.size(); i++){
			playerCards.at(i).printCard();
		}
		
		cout << endl;
		cout << "Hit? ('y' or 'n')" << endl;
		cin >> yorn;
		cin.ignore();
		cout << endl;
		
		if (yorn == 'y'){
			Card newCard = deck.dealCard();
			playerCards.push_back(newCard);
			playerTotal += newCard.getValue();
		}
		if ( playerTotal > 21){
			for (int i = index; i < playerCards.size(); i++){
				if ( playerCards.at(i).getName() == "Ace"){
					playerTotal -= 10;
				}
				index ++;
			}
		}
		
	}
	cout << "Dealer's Cards: " << endl;
	cout << "________________" << endl;
	cout << endl;
	for (int i = 0; i < dealerCards.size(); i++){
		dealerCards.at(i).printCard();
	}	
	cout << endl;
		
	cout << "Your cards: " << endl;
	cout << "________________" << endl;
	cout << endl;
	for (int i = 0; i < playerCards.size(); i++){
		playerCards.at(i).printCard();
	}
	cout << endl;
	
	index = 0;
	while (dealerTotal < 17){
		
		cout << "Dealer Hits" << endl;
		cout << endl;
		Card newcard = deck.dealCard();
		dealerCards.push_back(newcard);
		dealerTotal += newcard.getValue();
		cout << "Dealer's Cards: " << endl;
		cout << "________________" << endl;
		cout << endl;
		for (int i = 0; i < dealerCards.size(); i++){
			dealerCards.at(i).printCard();
		}	
		cout << endl;
		
		cout << "Your cards: " << endl;
		cout << "________________" << endl;
		cout << endl;
		for (int i = 0; i < playerCards.size(); i++){
			playerCards.at(i).printCard();
		}
		
		cout << endl;
		if ( dealerTotal > 21){
			
			for (int i = index; i < dealerCards.size(); i++){
				if ( dealerCards.at(i).getName() == "Ace"){
					dealerTotal -= 10;
				}
				index ++;
			}
		}
	}
	if (playerTotal > 21) {
		cout << "Player busts" << endl;
		myfile << "DEALERWIN" << endl;
		*playerMoney -= bet;
		cout << setprecision(2) <<fixed<< "$" << *playerMoney << endl;
	}

	else if (dealerTotal > 21){
		cout << "Player wins! dealer busts" << endl;
		myfile << "PLAYERWIN" << endl;
		*playerMoney += bet;
		cout << setprecision(2) <<fixed<< "$" << *playerMoney << endl;
	}
	else if ( playerTotal == dealerTotal){
		cout << "Push" << endl;
		cout << setprecision(2) <<fixed<< "$" << *playerMoney << endl;
	}
	else if ( playerTotal > dealerTotal ) {
		cout << "Player wins!" << endl;
		myfile << "PLAYERWIN" << endl;
		*playerMoney += bet;
		cout << setprecision(2) <<fixed<< "$" << *playerMoney << endl;
	}
	else if (dealerTotal > playerTotal){
		cout << "Player loses!" << endl;
		myfile << "DEALERWIN" << endl;
		*playerMoney -= bet;
		cout << setprecision(2) <<fixed<< "$" << *playerMoney << endl;
	}
	else if ((playerCards.at(0).getValue() == 10 && playerCards.at(1).getName() == "Ace") || (playerCards.at(0).getName() == "Ace" && playerCards.at(1).getValue() == 10)){
		
		cout << "Player wins!" << endl;

		myfile << "PLAYERWIN" << endl;

		*playerMoney += (bet + bet/2);
		cout << setprecision(2) <<fixed<< "$" << *playerMoney << endl;
		
	}
	else if ((dealerCards.at(0).getValue() == 10 && dealerCards.at(1).getName() == "Ace") || (dealerCards.at(0).getName() == "Ace" && dealerCards.at(1).getValue() == 10)){
		
		cout << "Dealer wins!" << endl;
		myfile << "DEALERWIN" << endl;
		*playerMoney -= bet;
		cout << setprecision(2) <<fixed<< "$" << *playerMoney << endl;
	}
	
	playerCards.clear();
	dealerCards.clear();
	return;
}

int main(){
	double playerMoney = 1000.00;
	char yorn;

	cout << "******************************************************************" << endl;
	cout << "|                     Welcome to Black Jack!                     |" << endl;
	cout << "|                     ______________________                     |" << endl;
	cout << "|                    21 or highest cards win                     |" << endl;
	cout << "|                        over 21 is bust                         |" << endl;
	cout << "|                                                                |" << endl;
	cout << "|                     Would you like to play?                    |" << endl;
	cout << "+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x+x" << endl;
	while (yorn != 'y' && yorn != 'n'){
		cout << "('y' for yes, 'n' for no)" << endl;
		
		cin >> yorn;
		cin.ignore();
		cout << yorn << endl;
	}
	if (yorn == 'n'){
		return 0;
	}
	cout << '\n' << endl;

	while (yorn != 'n'){
		if (yorn == 'y'){
			play(&playerMoney);
		}
		else {
			cout << "Invalid input, 'y' for yes, 'n' for no"<<endl;
		}
		
		cout<< "Play again?"<< endl;
		cin >> yorn;

	}
	return 0;
}
		
		
		
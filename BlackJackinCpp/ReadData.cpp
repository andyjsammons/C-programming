#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>



using namespace std;


int main(){
	fstream data;
	string line;
	int dealerwins = 0;
	int playerwins = 0;
	int blackjacks = 0;
	double perdealerwins;
	double perplayerwins;
	double perblackjacks;
	
	data.open("blackjackresults.txt",ios::in);
	
	
	if (data.fail()){
		cout << "No such file" << endl;
		return 0;
	}
	
	else {
		while (data >> line){
			if ( line == "DEALERWIN" ){
				dealerwins ++;
			}
			else if ( line == "PLAYERWIN"){
				playerwins ++;
			}
			else if (line == "BLACKJACK") {
				blackjacks ++;
			}
		}
	}
	
	perblackjacks = (double)blackjacks/(playerwins + dealerwins);
	perplayerwins = (double)playerwins/(playerwins + dealerwins);
	perdealerwins = (double)dealerwins/(playerwins + dealerwins);
	
	cout << "Percentage of blackjacks per win: %" << setprecision(2) << fixed << perblackjacks * 100 << endl;
	cout << "Percentage of player wins: %" << setprecision(2) << fixed << perplayerwins * 100 << endl;
	cout << "Percentage of dealer wins: %" << setprecision(2) << fixed <<  perdealerwins * 100 << endl;
	
	data.close();
	return 0;
}
	
	
	
	
	
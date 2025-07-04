#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;



int main(){
	
	char move = 0;
	int moves = 0;
	int xPos = 20;
	int yPos = 1;
	int trapX[25];
	int trapY[25];
	string maze[13];
	int index = 0;
	srand(time(NULL));
	
	maze[0] = "________________________________________";
	maze[1] = "|......................................|";
	maze[2] = "|.|-|.|------|.|________---------|.|-|.|";
	maze[3] = "|.|_|.|____  |.........|    _____|.|_|.|";
	maze[4] = "|.........|----------|.|____|..........|";
	maze[5] = "|.|-----|.....................|------|.|";
	maze[6] = "|.|    _|---------|.|---------|___   |.|";
	maze[7] = "|.|___|..........................|___|.|";
	maze[8] = "|.......|-|.|--------------|.|-|.......|";
	maze[9] = "|.|---|..........................|---|.|";
	maze[10] ="|.|___|-|.|-------|.|--------|.|-|___|.|";
	maze[11] ="|......................................|";
	maze[12] ="|-----------------|X|------------------|";
	

	maze[yPos][xPos] = 'O';
	while (1 != 0){
		cout << endl;
		cout << "*************************************************************************" << endl;
		cout << "                                Corn Doggus                              " << endl;
		cout << "*************************************************************************" << endl;
		cout << "      Make it to the X and dont run over any of the hidden traps!        " << endl;
		cout << endl;
		index = 0;
	while (index < 15){
			int x = rand() % 40;
			int y = rand() % 13;
			
			if (maze[y][x] == '.'){
				maze[y][x] = ',';
				trapX[index] = x;
				trapY[index] = y;
				index++;
			}
			
	}
		for (int i = 0; i < 13; i++){
			cout << maze[i] << endl;
		}
		cout << endl;
		cout << "Where would you like to move? ('w' for up, 's' for down, 'a'"<< '\n'<< "for left, 'd' for right, or 'q' to quit)" <<endl;
		cin >> move;
		
		
		//////MOVE RIGHT/////////
		if (move == 'd'){
			if (maze[yPos][xPos + 1] == '|'){
				cout << "invalid move, hotshot... Try again"<< endl;
				
			}
			else if (maze[yPos][xPos + 1] == ','){
				cout << endl;
				cout << endl;
				cout << "          ________________" <<endl;
				cout << "/\\.     ./               \\"<<endl;
				cout << "|  \\.../   YOU LOSE  !!   |_______________"<<endl;
				cout << "|Someone ate your corndog |_______________|"<<endl;
				cout << "\\________________________/	"<<endl;
				cout <<endl;
				break;
			}
			else {
				maze[yPos][xPos] = '.';
				maze[yPos][xPos+1] = 'O';
				xPos++;
				moves++;
			}
		}
		
		///////MOVE LEFT///////
		if (move == 'a'){
			if (maze[yPos][xPos - 1] == '|'){
				cout << "invalid move, hotshot... Try again"<< endl;
				
			}
			else if (maze[yPos][xPos - 1] == ','){
				cout << endl;
				cout << endl;
				cout << "          ________________" <<endl;
				cout << "/\\.     ./               \\"<<endl;
				cout << "|  \\.../   YOU LOSE  !!   |_______________"<<endl;
				cout << "|Someone ate your corndog |_______________|"<<endl;
				cout << "\\________________________/	"<<endl;
				cout <<endl;
				break;
			}
			else {
				maze[yPos][xPos] = '.';
				maze[yPos][xPos-1] = 'O';
				xPos--;
				moves++;
			}
		}
		////////MOVE UP/////////
		if (move == 'w'){
			if (maze[yPos - 1][xPos] == '-' || maze[yPos - 1][xPos] == '_'){
				cout << "invalid move, hotshot... Try again"<< endl;
				
			}
			else if (maze[yPos-1][xPos] == ','){
				cout << endl;
				cout << endl;
				cout << "          ________________" <<endl;
				cout << "/\\.     ./               \\"<<endl;
				cout << "|  \\.../   YOU LOSE  !!   |_______________"<<endl;
				cout << "|Someone ate your corndog |_______________|"<<endl;
				cout << "\\________________________/	"<<endl;
				cout <<endl;
				break;
			}
			else {
				maze[yPos][xPos] = '.';
				maze[yPos - 1][xPos] = 'O';
				yPos--;
				moves++;
			}
			
		}
		///////MOVE DOWN/////////
		if (move == 's'){
			if (maze[yPos+1][xPos] == '-' || maze[yPos+1][xPos] == '_'){
				cout << "invalid move, hotshot... Try again"<< endl;
				
			}
			else if (maze[yPos+1][xPos] =='X'){
				moves++;
				cout << endl;
				cout << "You win! you beat this game in " << moves << " moves!" << endl;
				cout << " _|_______________________" <<endl;
				cout << "/-o-                      \\"<<endl;
				cout << "| |  YOU WIN   !!      |  |_______________"<<endl;
				cout << "|  Enjoy your corndog -O- |_______________|"<<endl;
				cout << "\\______________________|__/	"<<endl;
				maze[yPos][xPos] = '.';
				break;
			}
			else if (maze[yPos+1][xPos] == ','){
				cout << endl;
				cout << endl;
				cout << "          ________________" <<endl;
				cout << "/\\.     ./               \\"<<endl;
				cout << "|  \\.../   YOU LOSE  !!   |_______________"<<endl;
				cout << "|Someone ate your corndog |_______________|"<<endl;
				cout << "\\________________________/	"<<endl;
				cout <<endl;
				break;
			}
			else {
				maze[yPos][xPos] = '.';
				maze[yPos+1][xPos] = 'O';
				yPos++;
				moves++;
			}
			
		}
		else if (move == 'q'){
			break;
		}
		
		for (int i = 0; i < 15; i++){
			maze[trapY[i]][trapX[i]] = '.';
		}
	}
		
		
	return 0;
}
		
		
		
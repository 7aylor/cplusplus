#include <iostream>
#include <string>

using namespace std;
const int boardLength = 3;

void initBoard(char (&grid)[boardLength][boardLength]);
void printGrid(char grid[boardLength][boardLength]);
void getCoordinates(string name, int playerKey, char (&grid)[boardLength][boardLength]);
void updateGrid(int x, int y, char (&grid)[boardLength][boardLength], char symbol);
bool checkGridForWinner(string name1, string name2, char grid[boardLength][boardLength]);

int main(){
	bool contPlay = true;
	char board[boardLength][boardLength];
	int playCount = 0;
	
	initBoard(board);
	string player1;
	string player2;	
	char playAgain;
	cout << "**** Welcome to Tic Tac Toe ****\n" << endl;
	cout << "Enter Player 1 Name: ";
	cin >> player1;
	cout << "Enter Player 2 Name: ";
	cin >> player2;
	cout << "Hello " << player1 << ", hello " << player2 << "." << endl;

	string player = player1;
	int key = 0;

	printGrid(board);

	while(contPlay == true){	
		while(contPlay == true)
		{
			if(playCount >= 9){
				cout << "Cat's game, its a draw!\n";
				contPlay = false;
			}
			
			if(playCount % 2 == 0){
				player = player1;
				key = 0;
			}
			else{
				player = player2;
				key = 1;
			}

			getCoordinates(player, key, board);
			contPlay = checkGridForWinner(player1, player2, board);
			
			playCount++;
			printGrid(board);
		}		
		
		cout << "Play again? (y/n): ";
		cin >> playAgain;
		while(playAgain != 'y' && playAgain != 'Y' && 
			playAgain != 'n' && playAgain != 'N'){
			cout << "Invalid input. Type a y for yes or n for no: ";
			cin >> playAgain;
		}
		if(playAgain == 'y' || playAgain == 'Y'){
			initBoard(board);
			printGrid(board);
			playCount = 0;
			contPlay = true;
		}
		else{
			contPlay = false;
		}
	}
	
	cout << "Thanks for playing!\n";

	return 0;
}

//init board
void initBoard(char (&grid)[boardLength][boardLength]){
	for(int i = 0; i < boardLength; i++){
		for(int j = 0; j < boardLength; j++){
			grid[i][j] = ' ';
		}
	}
}

void printGrid(char grid[boardLength][boardLength])
{
	cout << "_";
	for(int i = 0; i < boardLength; i++){
		cout << "|" << i + 1 << "|";
	}
	for(int i = 0; i < boardLength; i++){
	cout << endl << i + 1;
		for(int j = 0; j < boardLength; j++){
			cout << "|" << grid[i][j] << "|";
		}
	}
	cout << endl;
	 
}

void getCoordinates(string name, int playerKey, char (&grid)[boardLength][boardLength]){
	int x;
	int y;
	
	cout << name << "'s turn:" << endl;
	cout << "X: ";
	cin >> x;
	while(cin.fail() || x < 1 || x > boardLength){
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "incorrect value. Please try again.\n" << "X: ";
		cin >> x;
	}

	//decrement by 1 to stay in bounds of array
	x--;

	cout << "Y: ";
	cin >> y;
	while(cin.fail() || y < 1 || y > boardLength){
		cin.clear();
		cin.ignore(99999, '\n');
		cout << "incorrect value. Please try again.\n" << "Y: ";
		cin >> y;
	}
	
	//decrement by 1 to stay in bounds of array
	y--;

	if(grid[y][x] != ' '){
		cout << "That cell is already taken. Please pick a different one.\n";
		getCoordinates(name, playerKey, grid);
	}
	else{
		if(playerKey == 0)
			updateGrid(x, y, grid, 'x');
		else
			updateGrid(x, y, grid, 'o');
	}
}

void updateGrid(int x, int y, char (&grid)[boardLength][boardLength], char symbol){
	grid[y][x] = symbol;
}

bool checkGridForWinner(string name1, string name2, char grid[boardLength][boardLength]){
	for(int i = 0; i < boardLength; i++){
		//for(int j = 0; j < boardLength; j++){
			//horizontal
			if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] 
					&& grid[i][0] == 'x'){
				cout << name1 << " wins!" << endl;
				return false;
			}
			if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] 
					&& grid[i][0] == 'o'){
				cout << name2 << " wins!" << endl;
				return false;
			}
			//vertical
			if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] 
					&& grid[0][i] == 'x'){
				cout << name1 << " wins!" << endl;
				return false;
			}
			if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] 
					&& grid[0][i] == 'o'){
				cout << name2 << " wins!" << endl;
				return false;
			}
			//diagonal
			if((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] 
					&& grid[0][0] == 'x') || (grid[0][2] == grid[1][1] 
					&& grid[1][1] == grid[2][0] && grid[0][2] == 'x')){
				cout << name1 << " wins!" << endl;
				return false;
			}
			if((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] 
					&& grid[0][0] == 'o') || (grid[0][2] == grid[1][1] 
					&& grid[1][1] == grid[2][0] && grid[0][2] == 'o')){
				cout << name2 << " wins!" << endl;
				return false;
			}
		//}
	}
	return true;
}

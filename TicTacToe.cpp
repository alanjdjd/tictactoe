#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	bool compMove = false;
	bool playerMove = true;
	bool gameOver = false;
	const int ROWS = 3;
	const int COLLUMNS = 3;
	string ticTacToe[ROWS][COLLUMNS]; //declares tictactoe board

	srand(static_cast<unsigned int>(time(0))); //random seed

	cout << "  1 2 3\n1 _ _ _ \n2 _ _ _\n3 _ _ _" << endl; // first board showing coordinates

	int place[2]; 
	for (int i = 0; i < 9; i++) {
		if (i % 2 == 0) {
			while (playerMove) {
				cout << "Write coordinates" << endl << "First: ";
				cin >> place[1];
				cout << "Second: ";
				cin >> place[0];
				cout << endl;

				place[0] -= 1;
				place[1] -= 1;
				if (ticTacToe[place[0]][place[1]] == "o" || ticTacToe[place[0]][place[1]] == "x") {
					playerMove = true;
					cout << "Incorrect move\n";
				}
				else {
					playerMove = false;
					ticTacToe[place[0]][place[1]] = "x";
					compMove = true;
				}
				if (ticTacToe[0][0] == "x" && ticTacToe[0][1] == "x" && ticTacToe[0][2] == "x" || 
					ticTacToe[1][0] == "x" && ticTacToe[1][1] == "x" && ticTacToe[1][2] == "x" || 
					ticTacToe[2][0] == "x" && ticTacToe[2][1] == "x" && ticTacToe[2][2] == "x" || 
					ticTacToe[0][0] == "x" && ticTacToe[1][0] == "x" && ticTacToe[2][0] == "x" ||
					ticTacToe[0][1] == "x" && ticTacToe[1][1] == "x" && ticTacToe[2][1] == "x" ||
					ticTacToe[0][2] == "x" && ticTacToe[1][2] == "x" && ticTacToe[2][2] == "x" ||
					ticTacToe[0][0] == "x" && ticTacToe[1][1] == "x" && ticTacToe[2][2] == "x" ||
					ticTacToe[0][2] == "x" && ticTacToe[1][1] == "x" && ticTacToe[2][0] == "x") {
					cout << "Player won!";
					playerMove = false;
					compMove = false;
					gameOver = true;
				}
			}
		}
		else {
			while (compMove) {
				cout << endl;
				place[1] = rand() % 3;
				place[0] = rand() % 3;
				if (ticTacToe[place[0]][place[1]] == "o" || ticTacToe[place[0]][place[1]] == "x") {
					compMove = true;
				}
				else {
					ticTacToe[place[0]][place[1]] = "o";
					compMove = false;
					playerMove = true;
				}
				if (ticTacToe[0][0] == "o" && ticTacToe[0][1] == "o" && ticTacToe[0][2] == "o" ||
					ticTacToe[1][0] == "o" && ticTacToe[1][1] == "o" && ticTacToe[1][2] == "o" ||
					ticTacToe[2][0] == "o" && ticTacToe[2][1] == "o" && ticTacToe[2][2] == "o" ||
					ticTacToe[0][0] == "o" && ticTacToe[1][0] == "o" && ticTacToe[2][0] == "o" ||
					ticTacToe[0][1] == "o" && ticTacToe[1][1] == "o" && ticTacToe[2][1] == "o" ||
					ticTacToe[0][2] == "o" && ticTacToe[1][2] == "o" && ticTacToe[2][2] == "o" ||
					ticTacToe[0][0] == "o" && ticTacToe[1][1] == "o" && ticTacToe[2][2] == "o" ||
					ticTacToe[0][2] == "o" && ticTacToe[1][1] == "o" && ticTacToe[2][0] == "o") {
					for (int i = 0; i < ROWS; i++) {
						for (int j = 0; j < COLLUMNS; j++) {
							if (ticTacToe[i][j] == "") {
								ticTacToe[i][j] = "_";
							}
							if (j == 0) {
								cout << "  " + ticTacToe[i][j] + " ";
							}
							else {
								cout << ticTacToe[i][j] + " ";
							}
						}
						cout << endl;
					}
					cout << "Computer won!";
					playerMove = false;
					compMove = false;
					gameOver = true;
				}
			}
		}
		if (!gameOver) {
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLLUMNS; j++) {
					if (ticTacToe[i][j] == "") {
						ticTacToe[i][j] = "_";
					}
					if (j == 0) {
						cout << "  " + ticTacToe[i][j] + " ";
					}
					else {
						cout << ticTacToe[i][j] + " ";
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}




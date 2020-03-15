// Student Name: Ishaan Bhatt
// Student Number: 20779096
// SYDE 121 Lab Assignment 5
// Filename: lab04_01.cpp
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly plagiarized by others.
// Project:  Creating a 4x4 tic tac toe game
// Purpose: Using arrays and functions to createa 4x4 tic tac toe game that users can play.
/* In order to test the program logic, I inputed placement values that deviated from the 1
to 16 range and found that the program correctly outputted a return statement to the user declaring
the invalid input. I also made sure that a placement value was not repeated twice, by entering the same
value twice, and the program again correctly returned a invalid input statement back to the user. Finally
I tested the tic tac toe game over various trials and counted the number of ties, and wins for each team and found
that the final score was tallied up correctly.*/
// Due Date: Friday, October 26th
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string board[5][5]; // Creates the tic-tac-toe board

// Keeps track of whose move it is (1 for your move, 0 is not)
int x_wins = 0; //defining basic variables fundamental to tic tac toe game
int  move_2;
int o_wins = 0;
int ties = 0;
int games = 1;
int move_1;
char play_again, winner = '*';

// Prints the board to the console
void print_board() {
	for (int i = 1; i <= 4; i++) { //four rows and columns created through loop
		for (int j = 1; j <= 4; j++) {
			// Include proper amount of spaces for formatting
			if (board[i][j].length() == 1) {
				cout << board[i][j] << "      ";
			}
			else {
				cout << board[i][j] << "     ";
			}
		}
		cout << endl;
	}
}


void reset_game() { //function that restarts the game
	// this function would be included within the processing subcategory
	int count = 1; // Counter for filling up the board

	// Fill the board
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			board[i][j] = to_string(count++); // to_string converts the counter to string
		}
	}

	move_1 = (games % 2); // X moves first in the odd number games
	move_2 = 1 - move_1; // O has the opposite of move of X
	winner = '*'; // Filler winner
	print_board();
}

//
bool not_full() { // this function checks if there is any space available within the board
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (board[i][j] != "X" && board[i][j] != "O") {
				return true; //if condition are met not_full is defined as true
			}
		}
	}

	return false; //else return false
}

void winner_is() {
	//this function is used primarily to check whether player 1 or player 2 has secured a win through accumulation
	//of x's or o's. This is checked for horizontally, vertically, and also diagonally.
	string val;
	bool flag; //boolean operator to store winner information

	//checks if either player has secured a win through accumulation of X's or O's horizontally
	for (int i = 1; i <= 4; i++) {
		val = board[i][1];
		flag = true;

		for (int j = 2; j <= 4; j++) {
			if (val != board[i][j]) {
				flag = false;
			}
		}
		if (flag) {
			if (val == "X") {
				winner = 'X';
			}
			else {
				winner = 'O';
			}
			return;
		}
	}

	// Checks if either player has secured a win through accumulation of x's or o's vertically
	for (int i = 1; i <= 4; i++) {
		val = board[1][i];
		flag = true;

		for (int j = 2; j <= 4; j++) {
			if (val != board[j][i]) {
				flag = false;
			}
		}
		if (flag) {
			if (val == "X") {
				winner = 'X';
			}
			else {
				winner = 'O';
			}
			return;
		}
	}

	val = board[1][1]; // this checks if a win has been acheived by either player
	//by checking accumulatoin of x's or o's diagonally from left to right
	flag = true;
	for (int i = 2; i <= 4; i++) { //for loop used to check conditions
		if (val != board[i][i]) {
			flag = false;
		}
	}
	if (flag) {
		if (val == "X") {
			winner = 'X';
		}
		else {
			winner = 'O';
		}
		return;
	}

	//Checks if a win has been acheived by player 1 or 2 through accumulation of x's or o's diagonally from right to left

	val = board[1][4];
	flag = true;
	for (int i = 2; i <= 4; i++) {
		if (val != board[i][5 - i]) {
			flag = false;
		}
	}
	if (flag) {
		if (val == "X") {
			winner = 'X';
		}
		else {
			winner = 'O';
		}
		return;
	}
}

void moves() {
	int placement; // declaring integer variable placement

	do {
		if (move_1) {
			cout << "player 1, choose where you want to place your cross "; //outputs command for player to guide them through game
		}
		else {
			cout << "player 2, choose where you would like to place your O: "; // output command for player to guide them through game
		}
		cin >> placement;

		int row = ceil((double)placement / 4);
		int col = placement % 4;
		if (!col) col += 4;

		if (placement >= 1 && placement <= 16 && board[row][col] != "X" && board[row][col] != "O") {
			// if the placement is between 1 and 16 then move is allowed as long as it has not
			//already been occupied. Otherwise placement is not allowed.
			if (move_1) {
				board[row][col] = "X";
			}
			else {
				board[row][col] = "O";
			}
			print_board(); //calling a function print_board
			winner_is(); //calling a function winner_is
			move_1 = move_2;
			move_2 = 1 - move_1;
		}
		else {
			cout << "This square within the board is already occupied or not within the domain of the game." << endl;
		}
	} while (winner == '*' && not_full());
	//checks to make sure board is not full and no platers have won to determine whether loop should be continued
}


int main() { //main function
	do {
		reset_game();
		moves();

		if (winner == 'X') { // outputs results of the tic tac toe game
			cout << " player 1 wins !!" << endl; //output statement for declaring winner
			x_wins++; //adds to the integer number of  x_wins
		}
		else if (winner == 'O') {
			cout << "player 2 wins!!" << endl;
			o_wins++; //adds to the integer number of 0_wins
		}
		else {
			cout << "player 2 and 1 have tied" << endl;
			ties++;
		}

		games++;
		cout << "would you like to play again?"; //option available to player if they want to play again
		cin >> play_again;
	} while (play_again == 'Y'); // continue to play again while player wants to


	cout << "player 1 won " << x_wins << " times)." << endl; //outputting player 1 wins

	cout << "player 2 won " << o_wins << " times." << endl; // outputting player 2 wins

	cout << "player 1 and player 2 tied a total of  " << ties << " times" << endl; // outputiing number of ties

	return 0;
}

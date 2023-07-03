#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOARD_SIZE = 10;
const char EMPTY = ' ';
const char BALL = 'O';
const char PLAYER = 'P';

int main(){
	srand(time(0));
	
	 char board[BOARD_SIZE][BOARD_SIZE];
    int playerRow = BOARD_SIZE - 1;
    int playerCol = BOARD_SIZE / 2;
    int ballRow = 0;
    int ballCol = rand() % BOARD_SIZE;
    
    //initilazing board
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            board[row][col] = EMPTY;
        }
    }
      board[playerRow][playerCol] = PLAYER;
    board[ballRow][ballCol] = BALL;
    
    bool gameRunning= true;
    int score=0;
    
    while(gameRunning){
    	system("cls");
      for (int row = 0; row < BOARD_SIZE; ++row) {
            for (int col = 0; col < BOARD_SIZE; ++col) {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }	
        
        char move;
        cout << "Enter your move (a - left, d - right): ";
        cin >> move;
         board[playerRow][playerCol] = EMPTY;
         
       if (move == 'a' && playerCol > 0) {
            --playerCol;
        } else if (move == 'd' && playerCol < BOARD_SIZE - 1) {
            ++playerCol;
        }
  
        board[playerRow][playerCol] = PLAYER;
		
		 board[ballRow][ballCol] = EMPTY;
		 
        if (ballRow < playerRow) {
            ++ballRow;
        } else {
            // Randomly move the ball left or right
            int direction = rand() % 2;
            if (direction == 0 && ballCol > 0) {
                --ballCol;
            }
            else if (direction == 1 && ballCol < BOARD_SIZE - 1) {
                ++ballCol;
            }
            ++ballRow;
        }
        if (ballRow == playerRow && ballCol == playerCol) {
            ++score;
            ballRow = 0;
            ballCol = rand() % BOARD_SIZE;
        }
 board[ballRow][ballCol] = BALL;
 
 if (ballRow == BOARD_SIZE - 1) {
            gameRunning = false;
        }
    
    
	}//while
	cout << "Game over! Your score: " << score << endl;
	return 0;
	
}//main

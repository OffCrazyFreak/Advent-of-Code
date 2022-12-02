#include <iostream>
#include <cmath>

using namespace std;

int main (void){
    int numOfBoards = 100; // 100
    int boardSize = 5;
    int board[numOfBoards][boardSize][boardSize];
    bool filledBoard[numOfBoards][boardSize][boardSize];
    int numOfNums = 100; // 100
    int nums[numOfNums];
    char c; // delimeter

    for (int i = 0; i < numOfNums; i++){
        cin >> nums[i];
        cin >> c;
    }
    // for(int num : nums) cout << num << endl;

    // load all boards into a 3D matrix
    for (int i = 0; i < numOfBoards; i++){
        for (int j = 0; j < boardSize; j++){
            for (int k = 0; k < boardSize; k++){
                cin >> board[i][j][k];
                filledBoard[i][j][k] = false;
            }
        }
    }
    
    
    int bingoCounter = 0;
    int winningNumber = -1;
    int unmarkedSum = 0;

    // draw numbers until a row or column is filled
    for(int num : nums){
        for (int i = 0; i < numOfBoards; i++){
            for (int j = 0; j < boardSize; j++){
                for (int k = 0; k < boardSize; k++){
                    if(board[i][j][k] == num){
                        filledBoard[i][j][k] = true;

                        // check if all numbers in line are filled
                        for (int index = 0; index < boardSize; index++){
                            if(filledBoard[i][j][index] == true){
                                bingoCounter++;
                            }
                        }
                        if (bingoCounter != 5){
                            bingoCounter = 0;

                            // check if all numbers in column are filled
                            for (int index = 0; index < boardSize; index++){
                                if(filledBoard[i][index][k] == true){
                                    bingoCounter++;
                                }
                            }
                            if (bingoCounter != 5)
                                bingoCounter = 0;
                        }
                        if(bingoCounter != 0){
                            // sum unmarked numbers on that board
                            for (int x = 0; x < boardSize; x++){
                                for (int y = 0; y < boardSize; y++){
                                    if(filledBoard[i][x][y] == false){
                                        unmarkedSum += board[i][x][y];
                                    }
                                }
                            }
                            winningNumber = num;
                        }
                    }
                    if(winningNumber != -1) break; // optimization
                }
                if(winningNumber != -1) break; // optimization
            }
            if(winningNumber != -1) break; // optimization
        }
        if(winningNumber != -1) break; // optimization
    }

    cout << "Winning number: " << winningNumber << " | Unmarked sum: " << unmarkedSum << endl;
    cout << "Result: " << winningNumber * unmarkedSum << endl;

    return 0;
}
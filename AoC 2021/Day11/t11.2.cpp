#include <iostream>

using namespace std;

int main(void){
    int matrixSize = 10; // 10
    int matrix[matrixSize][matrixSize];
    char c;
    int flashStepCount;

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            cin >> c;
            matrix[i][j] = c - 48;
        }
    }

    int step = 0;
    while(flashStepCount != matrixSize*matrixSize){ // repeats until all of them flash
        for(int i = 0; i < matrixSize; i++){
            for(int j = 0; j < matrixSize; j++){
                matrix[i][j]++;

                for(int k = 0; k < matrixSize; k++){
                    for(int l = 0; l < matrixSize; l++){
                        if(matrix[k][l] > 9){
                            // increase all adjacent, except for those outside of matrix
                            if (k != matrixSize - 1){
                                if(l != matrixSize - 1)
                                    matrix[k+1][l+1]++;
                                matrix[k+1][l]++;
                                if(l != 0)
                                    matrix[k+1][l-1]++;
                            } 
                            if(l != matrixSize - 1)
                                matrix[k][l+1]++;
                            if(l != 0)
                                matrix[k][l-1]++;
                            if (k != 0){
                                if(l != matrixSize - 1)
                                    matrix[k-1][l+1]++;
                                matrix[k-1][l]++;
                                if(l != 0)
                                    matrix[k-1][l-1]++;
                            }
                            

                            matrix[k][l] = -9; // set value for reset
                            // start the testing over again
                            k = 0;
                            l = 0;
                        }
                    }
                }
            }
        }

        // reset values over 9
        flashStepCount = 0;
        for(int i = 0; i < matrixSize; i++){
            for(int j = 0; j < matrixSize; j++){
                if(matrix[i][j] < 0){
                    matrix[i][j] = 0;
                    flashStepCount++;
                }
            }
        }

        /*
        // print out the matrix
        cout << endl << "After step " << step + 1 << ":" << endl;
        for(int i = 0; i < matrixSize; i++){
            for(int j = 0; j < matrixSize; j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }*/

        step++;
    }

    cout << "First total flash step: " << step << endl;

    return 0;
}
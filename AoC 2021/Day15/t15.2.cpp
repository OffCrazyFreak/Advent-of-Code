#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int matrixSizeMultiplier = 5; // 5
    int inputMatrixSize = 100; // 100
    char c;
    int matrix[inputMatrixSize * matrixSizeMultiplier][inputMatrixSize * matrixSizeMultiplier];
    int distances[inputMatrixSize * matrixSizeMultiplier][inputMatrixSize * matrixSizeMultiplier];

    // input values for first tile
    for(int i = 0; i < inputMatrixSize; i++){
        for(int j = 0; j < inputMatrixSize; j++){
            cin >> c;
            matrix[i][j] = c - 48;

            distances[i][j] = INT_MAX / 2; // could be fixed using -1 and if distance less || distance = -1 when calculating
        }
    }

    // calculate values for other tiles
    for(int tileX = 0; tileX < matrixSizeMultiplier; tileX++){
        for(int tileY = 0; tileY < matrixSizeMultiplier; tileY++){
            if(tileX == 0 && tileY == 0)
                tileY = 1;

            for(int i = 0; i < inputMatrixSize; i++){
                for(int j = 0; j < inputMatrixSize; j++){
                    //cout << "Value: " << matrix[i + inputMatrixSize * tileX][j + inputMatrixSize * tileY] << endl;
                    if(tileX == 0)
                        if(matrix[i][j + inputMatrixSize * (tileY - 1)] == 9)
                            matrix[i][j + inputMatrixSize * tileY] = 1;
                        else
                            matrix[i][j + inputMatrixSize * tileY] = matrix[i][j + inputMatrixSize * (tileY - 1)] + 1;
                    else
                        if(matrix[i + inputMatrixSize * (tileX - 1)][j + inputMatrixSize * tileY] == 9)
                            matrix[i + inputMatrixSize * tileX][j + inputMatrixSize * tileY] = 1;
                        else
                            matrix[i + inputMatrixSize * tileX][j + inputMatrixSize * tileY] = matrix[i + inputMatrixSize * (tileX - 1)][j + inputMatrixSize * tileY] + 1;

                    distances[i + inputMatrixSize * tileX][j + inputMatrixSize * tileY] = INT_MAX / 2; // could be fixed using -1 and if distance less || distance = -1 when calculating
                }
            }
        }
    }

    // set starting position
    int i = 0;
    int j = 0;
    distances[i][j] = 0;
    matrix[i][j] = -1;

    // dijkstras algorithm
    int shorttestPath;
    int nextI, nextJ;
    while(!(i == inputMatrixSize * matrixSizeMultiplier - 1 && j == inputMatrixSize * matrixSizeMultiplier - 1)){

        // calculate minimum distances to neighbouring elements 
        if(i != 0 && matrix[i-1][j] != -1){
            distances[i-1][j] = min(distances[i-1][j], distances[i][j] + matrix[i-1][j]);
        }
        if(i != inputMatrixSize * matrixSizeMultiplier - 1 && matrix[i+1][j] != -1){
            distances[i+1][j] = min(distances[i+1][j], distances[i][j] + matrix[i+1][j]);
        }
        if(j != 0 && matrix[i][j-1] != -1){
            distances[i][j-1] = min(distances[i][j-1], distances[i][j] + matrix[i][j-1]);
        }
        if(j != inputMatrixSize * matrixSizeMultiplier - 1 && matrix[i][j+1] != -1){
            distances[i][j+1] = min(distances[i][j+1], distances[i][j] + matrix[i][j+1]);
        }

        // find next lowest distance element
        
        shorttestPath = INT_MAX / 2;
        for (int k = 0; k < inputMatrixSize * matrixSizeMultiplier; k++)
            for (int l = 0; l < inputMatrixSize * matrixSizeMultiplier; l++)
                if(shorttestPath > distances[k][l] && matrix[k][l] != -1){
                    shorttestPath = distances[k][l];
                    nextI = k;
                    nextJ = l;
                }
        
        
        // cout << "Next i, j: " << nextI << "," << nextJ << " | Distance to it: " << distances[nextI][nextJ] << endl;
        matrix[nextI][nextJ] = -1; // make element unavailable (aka has been visited)
        // move to next lowest distance element
        i = nextI;
        j = nextJ;
    }

    cout << "Minimal distance from top left to bottom right using dijkstra is: " << distances[i][j] << endl;

    return 0;
}
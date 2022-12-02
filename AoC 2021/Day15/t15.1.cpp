#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int matrixSize = 100; // 100
    char c;
    int matrix[matrixSize][matrixSize];
    int distances[matrixSize][matrixSize];

    // input values
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            cin >> c;
            matrix[i][j] = c - 48;

            distances[i][j] = INT_MAX / 2;
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
    while(!(i == matrixSize - 1 && j == matrixSize - 1)){

        // calculate minimum distances to neighbouring elements 
        if(i != 0 && matrix[i-1][j] != -1){
            distances[i-1][j] = min(distances[i-1][j], distances[i][j] + matrix[i-1][j]);
        }
        if(i != matrixSize - 1 && matrix[i+1][j] != -1){
            distances[i+1][j] = min(distances[i+1][j], distances[i][j] + matrix[i+1][j]);
        }
        if(j != 0 && matrix[i][j-1] != -1){
            distances[i][j-1] = min(distances[i][j-1], distances[i][j] + matrix[i][j-1]);
        }
        if(j != matrixSize - 1 && matrix[i][j+1] != -1){
            distances[i][j+1] = min(distances[i][j+1], distances[i][j] + matrix[i][j+1]);
        }

        // find next lowest distance element
        shorttestPath = INT_MAX / 2;
        for (int k = 0; k < matrixSize; k++)
            for (int l = 0; l < matrixSize; l++)
                if(shorttestPath > distances[k][l] && matrix[k][l] != -1){
                    shorttestPath = distances[k][l];
                    nextI = k;
                    nextJ = l;
                }

        
        //cout << "Next i, j: " << nextI << "," << nextJ << " | Distance to it: " << distances[nextI][nextJ] << endl;
        matrix[nextI][nextJ] = -1; // make element unavailable (aka has been visited)
        // move to next lowest distance element
        i = nextI;
        j = nextJ;
    }

    cout << "Minimal distance from top left to bottom right using dijkstra is: " << distances[i][j] << endl;

    return 0;
}
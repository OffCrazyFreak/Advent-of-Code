#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isLowPoint(int matrix[], int i, int j, int numOfRows, int numOfColumns){
    // cout << "Checking: " << matrix[i*numOfColumns + j] << " | ";
    if(j != 0 && matrix[i*numOfColumns + j] >= matrix [i*numOfColumns + j-1])
        return false; // if bigger than left element
    if(j != numOfColumns - 1 && matrix[i*numOfColumns + j] >= matrix[i*numOfColumns + j+1])
        return false; // if bigger than right element
    if(i != 0 && matrix[i*numOfColumns + j] >= matrix[i*numOfColumns-1*numOfColumns + j])
        return false; // if bigger than top element
    if(i != numOfRows - 1 && matrix[i*numOfColumns + j] >= matrix[i*numOfColumns+1*numOfColumns + j])
        return false; // if bigger than bottom element

    return true;
}

int main (void){

    int numOfRows = 100; // 100
    int numOfColumns = 100; // 100
    int matrix[numOfRows][numOfColumns];
    char c;
    int sumOfLowestPointsPlusOne = 0;

    for (int i = 0; i < numOfRows; i++){
        for(int j = 0; j < numOfColumns; j++){
            cin >> c;
            matrix[i][j] = c - 48;
        }
    }

    /* 
    // print out matrix
    for (int i = 0; i < numOfRows; i++){
        for(int j = 0; j < numOfColumns; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }*/

    for (int i = 0; i < numOfRows; i++){
        for(int j = 0; j < numOfColumns; j++){
            /* 
            // dirty way
            if((i == 0 && j == 0 && matrix[i][j] < matrix[i+1][j] && matrix[i][j] < matrix[i][j+1]) ||
            (i == 0 && j == numOfColumns - 1 && matrix[i][j] < matrix[i+1][j] && matrix[i][j] < matrix[i][j-1]) ||
            (i == numOfRows - 1 && j == 0 && matrix[i][j] < matrix[i-1][j] && matrix[i][j] < matrix[i][j+1]) ||
            (i == numOfRows - 1 && j == numOfColumns - 1 && matrix[i][j] < matrix[i-1][j] && matrix[i][j] < matrix[i][j-1]) ||
            (i == 0 && matrix[i][j] < matrix[i+1][j] && matrix[i][j] < matrix[i][j+1] && matrix[i][j] < matrix[i][j-1]) ||
            (j == numOfColumns - 1 && matrix[i][j] < matrix[i+1][j] && matrix[i][j] < matrix[i][j-1] && matrix[i][j] < matrix[i-1][j]) ||
            (j == 0 && matrix[i][j] < matrix[i-1][j] && matrix[i][j] < matrix[i][j+1] && matrix[i][j] < matrix[i+1][j]) ||
            (i == numOfRows - 1 && matrix[i][j] < matrix[i-1][j] && matrix[i][j] < matrix[i][j-1] && matrix[i][j] < matrix[i][j+1]) ||
            (matrix[i][j] < matrix[i-1][j] && matrix[i][j] < matrix[i][j-1] && matrix[i][j] < matrix[i+1][j] && matrix[i][j] < matrix[i][j+1])){
                // cout << "Matrix[" << i << "][" << j << "]=" << matrix[i][j] << endl;
                sumOfLowestPointsPlusOne += matrix[i][j] + 1;
            }*/

            // clean way
            if(isLowPoint(matrix[0], i, j, numOfRows, numOfColumns)){
                // cout << isLowPoint(matrix[0], i, j, numOfRows, numOfColumns) << endl;
                sumOfLowestPointsPlusOne += matrix[i][j] + 1;
            }

        }
    }

    cout << "Sum + 1*x: " << sumOfLowestPointsPlusOne << endl;

    return 0;
}
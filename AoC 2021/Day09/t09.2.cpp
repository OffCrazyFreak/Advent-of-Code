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

void getBasinSize(int matrix[], int i, int j, int numOfRows, int numOfColumns, int *basinSize){
    cout << *basinSize << endl;
    if(matrix[i*numOfColumns + j] == 9){        
        (*basinSize)--;
    }else{/*
        if(j != 0 && matrix[i*numOfColumns + j] <= matrix [i*numOfColumns + j-1])
            getBasinSize(matrix, i, j-1, numOfRows, numOfColumns, basinSize + 1); // if smaller than left element
        if(j != numOfColumns - 1 && matrix[i*numOfColumns + j] <= matrix[i*numOfColumns + j+1])
            getBasinSize(matrix, i, j+1, numOfRows, numOfColumns, &(++(*basinSize))); // if smaller than right element
        if(i != 0 && matrix[i*numOfColumns + j] <= matrix[i*numOfColumns-1*numOfColumns + j])
            getBasinSize(matrix, i-1, j, numOfRows, numOfColumns, &(++(*basinSize))); // if smaller than top element
        if(i != numOfRows - 1 && matrix[i*numOfColumns + j] <= matrix[i*numOfColumns+1*numOfColumns + j])
            getBasinSize(matrix, i+1, j, numOfRows, numOfColumns, &(++(*basinSize))); // if smaller than bottom element
    */}
}

int main (void){

    int numOfRows = 10; // 100
    int numOfColumns = 5; // 100
    int matrix[numOfRows][numOfColumns];
    char c;
    int basinSize = 0;

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
            if(isLowPoint(matrix[0], i, j, numOfRows, numOfColumns)){
                // cout << isLowPoint(matrix[0], i, j, numOfRows, numOfColumns) << endl;
                getBasinSize(matrix[0], i, j, numOfRows, numOfColumns, &basinSize); // call getBasinSize with low point

                cout << "Basin size: " << basinSize << endl;
            }

        }
    }


    return 0;
}
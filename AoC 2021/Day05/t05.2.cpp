#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (void){

    int inputs = 500; // 500
    int matrixSize = 1000; // 1000
    char c;
    int x1, y1, x2, y2;
    int matrix[matrixSize][matrixSize];
    memset(matrix, 0, sizeof(matrix)); // set matrix to all zeros
    int overlappingPoints = 0;

    for (int i = 0; i < inputs; i++){
        // x and y are reversed, probs a mistake on their part
        cin >> y1;
        cin >> c;
        cin >> x1;
        for(int j = 0; j < 2; j++){ // 2 because cin ignores whitespaces
            cin >> c;
        }
        cin >> y2;
        cin >> c;
        cin >> x2;
       
        if(x2 - x1 == y2 - y1){
            // example 1,1 -> 3,3 || 0,2 -> 4,6
            // cout << "Falling diagonal!" << endl;
            for (int j = 0; j < abs(x2 - x1) + 1; j++){
                // cout << min(x1, x2) + j << "|" << min(y1, y2) + j << endl; 
                matrix[min(x1, x2) + j][min(y1, y2) + j]++;
            }
        }else if((x2 - x1) == -(y2 - y1)){
            // example 4,0 -> 1,3 || 1,3 -> 4,0
            // cout << "Rising diagonal!" << endl;
            for (int j = 0; j < abs(x2 - x1) + 1; j++){
                // cout << min(x1, x2) + j << "|" << max(y1, y2) - j << endl; 
                matrix[min(x1, x2) + j][max(y1, y2) - j]++;
            }
        }else if(y1 == y2){
            // cout << "Same Y coords!" << endl;
            for (int j = 0; j < abs(x2 - x1) + 1; j++){
                matrix[min(x1, x2) + j][y1]++;
            }
        }else if(x1 == x2){
            // cout << "Same X coords!" << endl;
            for (int j = 0; j < abs(y2 - y1) + 1; j++){
                matrix[x1][min(y1, y2) + j]++;
            }
        }
    }

    for(int i = 0; i < matrixSize; i++)
        for(int j = 0; j < matrixSize; j++)
            if(matrix[i][j] >= 2)
                overlappingPoints++;

    /*
    // print out matrix
    cout << endl;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++)
            cout << matrix[i][j];
        cout << endl;
    }*/

    cout << "Overlapping points: " << overlappingPoints << endl;

    return 0;
}
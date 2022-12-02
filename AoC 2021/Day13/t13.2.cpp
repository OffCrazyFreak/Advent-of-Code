#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (void){
    char c;
    int inputs = 776; // 776
    int folds = 12; // 12
    char foldDirection;
    int foldLine;
    int data[inputs][2]; // 2 for x and y
    int xMax = 0;
    int yMax = 0;

    for(int input = 0; input < inputs; input++){
        cin >> data[input][0];
        if(data[input][0] >= yMax)
            yMax = data[input][0] + 1;
        cin >> c;
        cin >> data[input][1];
        if(data[input][1] >= xMax)
            xMax = data[input][1] + 1;
    }

    /*for (int i = 0; i < inputs; i++){
        cout << data[i][0] << "|" << data[i][1] << endl;
    }*/
    //cout << "xMax: " << xMax << " | yMax: " << yMax << endl;

    bool matrix[xMax][yMax];
    memset(matrix, 0, sizeof(matrix));

    for(int input = 0; input < inputs; input++){
        matrix[data[input][1]][data[input][0]] = 1;
    }

    // print out matrix
    /*for (int i = 0; i < xMax; i++){
        for (int j = 0; j < yMax; j++){
            if(matrix[i][j])
                cout << "#";
            else
                cout << "-";
        }
        cout << endl;
    }*/
    
    for(int i = 0; i < folds; i++){
        for(int j = 0; j < 11; j++){
            cin >> c;
            if(j == 9)
                foldDirection = c;
        }
        cin >> foldLine;
        // cout << "Fold at: " << foldDirection << "=" << foldLine << endl;

        if(foldDirection == 'x'){
            // fold in direction x
            for (int i = 0; i < xMax; i++){
                for (int j = foldLine + 1; j < yMax; j++){
                    matrix[i][foldLine - (j - foldLine)] = matrix[i][j] || matrix[i][foldLine - (j - foldLine)];
                }
            }
            yMax = foldLine;
        }else{
            // fold in direction y
            for (int i = foldLine + 1; i < xMax; i++){
                for (int j = 0; j < yMax; j++){
                    matrix[foldLine - (i - foldLine)][j] = matrix[i][j] || matrix[foldLine - (i - foldLine)][j];
                }
            }
            xMax = foldLine;
        }
    }

    // print out matrix, aka code
    for (int i = 0; i < xMax; i++){
        for (int j = 0; j < yMax; j++){
            if(matrix[i][j])
                cout << "#";
            else
                cout << " ";
        }
        cout << endl;
    }

    
    return 0;
}
#include <iostream>

using namespace std;

int main (void){

    int numOfInputs = 200; // 200
    // int count[10] = {0};
    int sum = 0;
    string str;

    for (int i = 0; i < numOfInputs; i++){ // for each line
        for(int j = 0; j < 15; j++){ // for each string
            cin >> str;
            if((j > 10) && (str.length() == 2 || str.length() == 3 || str.length() == 4 || str.length() == 7)){
                sum++; // count digits 1, 4, 7 and 8 after | delimeter
            }
        }
    }

    cout << "Number of numbers 1, 4, 7, or 8: " << sum << endl;

    return 0;
}
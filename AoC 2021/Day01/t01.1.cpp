#include <iostream>

using namespace std;

int main(void){
    int inputs = 2000;
    int depths[inputs];
    int count = 0;

    for (int i = 0; i < inputs; i++){
        cin >> depths[i];
        if (i != 0 && depths[i] > depths[i-1]){
            count++;
        }
    }

    cout << "Number of increases: " << count;
    return 0;
}
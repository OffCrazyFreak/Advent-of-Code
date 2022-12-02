#include <iostream>
#include <cstring>

using namespace std;

int main (void){
    int inputs = 3;
    string command;
    int fwdCount = 0;
    int aim = 0;
    int depthChange = 0;
    int amount;

    for (int i = 0; i < inputs; i++){
        cin >> command;
        cin >> amount;
        if (command[0] == 'f'){
            fwdCount += amount;
            depthChange += amount * aim;
        } else if (command[0] == 'd'){
            aim += amount;
        } else if (command[0] == 'u'){
            aim -= amount;
        }
    }

    cout << "Change multiplication: " << fwdCount << " * " << depthChange << " = " << fwdCount * depthChange << endl;

    return 0;
}
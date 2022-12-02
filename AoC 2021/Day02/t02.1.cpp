#include <iostream>
#include <cstring>

using namespace std;

int main (void){
    int inputs = 1000;
    string command;
    int fwdCount = 0;
    int depthChange = 0;
    int amount;

    for (int i = 0; i < inputs; i++){
        cin >> command;
        cin >> amount;
        if (command[0] == 'f')
            fwdCount += amount;
        else if (command[0] == 'd')
            depthChange += amount;
        else if (command[0] == 'u')
            depthChange -= amount;
    }

    cout << "Change multiplication: " << fwdCount << " * " << depthChange << " = " << fwdCount * depthChange << endl;

    return 0;
}
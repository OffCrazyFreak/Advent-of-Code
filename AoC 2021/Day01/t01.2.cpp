#include <iostream>

using namespace std;

int main(void){
    int inputs = 2000;
    int depths[inputs];
    int count = 0, lastThreeMeasurmentWindow, currentThreeMeasurmentWindow;

    for (int i = 0; i < inputs; i++){
        cin >> depths[i];

        if (i > 2){
            lastThreeMeasurmentWindow = depths[i - 1] + depths[i - 2] + depths[i - 3];
            currentThreeMeasurmentWindow = depths[i] + depths[i - 1] + depths[i - 2];
            if(currentThreeMeasurmentWindow > lastThreeMeasurmentWindow)
                count++;
        }
    }

    cout << "Number of increases: " << count;
    return 0;
}
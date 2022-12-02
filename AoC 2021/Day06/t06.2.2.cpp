#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (void){
    int initalFishNumber = 5; // 300
    int reverseAge[9] = {0};
    int fish;
    char delimiter;
    int numOfDays = 18; // 256
    int sum = 0;

    for(int i = 0; i < initalFishNumber; i++){
        cin >> fish;
        reverseAge[fish]++;
        cin >> delimiter;
    }

    for (int i = 0; i < numOfDays; i++){
        if(i % 7 == 0){
            
        }
        
    }

    for(int num : reverseAge)
        sum += num;

    cout << "Number of fishies: " << sum << endl;

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (void){
    int initalFishNumber = 300; // 300
    int todaysFishNumber;
    int fish;
    char delimiter;
    vector<int> fishies;
    int numOfDays = 80; // 80

    // input initial life cycles
    for(int i = 0; i < initalFishNumber; i++){
        cin >> fish;
        fishies.push_back(fish);
        cin >> delimiter;
    }

    for(int i = 0; i < numOfDays; i++){
        todaysFishNumber = fishies.size(); // so the loop only goes through the fishies born before today
        for(int j = 0; j < todaysFishNumber; j++){
            if(fishies[j] == 0){
                // spawn a new fishie and reset counter for old fishie
                fishies.push_back(8);
                fishies[j] = 6;
            } else {
                // lower counter by uno
                fishies[j]--;
            }
        
        }
        cout << "Number of fishies after " << i + 1 << " days: " << fishies.size() << endl;
    }


    return 0;
}
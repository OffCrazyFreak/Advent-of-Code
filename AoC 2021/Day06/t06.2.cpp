#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (void){
    int initalFishNumber = 300; // 300
    int todaysFish1Number, todaysFish2Number;
    int fish;
    char delimiter;
    vector<int> fishies1;
    vector<int> fishies2;
    int numOfDays = 256; // 256

    for(int i = 0; i < initalFishNumber; i++){
        cin >> fish;
        if(i % 2 == 0)
            fishies1.push_back(fish);
        else
            fishies2.push_back(fish);
        cin >> delimiter;
    }

    // working, but not for big numbers (loops too long)
    for(int i = 0; i < numOfDays; i++){
        todaysFish1Number = fishies1.size(); // so the loop only goes through the fishies born before today
        todaysFish2Number = fishies2.size(); // so the loop only goes through the fishies born before today
        for(long long int j = 0; j < todaysFish1Number; j++){
            if(numOfDays - i > 6){
                // instead of going day by day, we can go 6 by 6 days 
                // as a fish can make only 1 other fish every 6 days
                fishies1[j] -= 6;
                // cout << fishies1[j] << endl;

                if(fishies1[j] < 0){
                    // spawn a new fishie and reset counter for old fishie
                    fishies1.push_back(9 + fishies1[j]);
                    // cout << "New fish!" << endl;
                    fishies1[j] = 7 + fishies1[j];
                }
            } else {
                if(fishies1[j] == 0){
                    // spawn a new fishie and reset counter for old fishie
                    fishies1.push_back(8);
                    fishies1[j] = 6;
                } else {
                    // lower counter by uno
                    fishies1[j]--;
                }
            }
        }
        for(long long int j = 0; j < todaysFish2Number; j++){
            if(numOfDays - i > 6){
                // instead of going day by day, we can go 6 by 6 days 
                // as a fish can make only 1 other fish every 6 days
                fishies2[j] -= 6;
                // cout << fishies2[j] << endl;

                if(fishies2[j] < 0){
                    // spawn a new fishie and reset counter for old fishie
                    fishies2.push_back(9 + fishies2[j]);
                    // cout << "New fish!" << endl;
                    fishies2[j] = 7 + fishies2[j];
                }
            } else {
                if(fishies2[j] == 0){
                    // spawn a new fishie and reset counter for old fishie
                    fishies2.push_back(8);
                    fishies2[j] = 6;
                } else {
                    // lower counter by uno
                    fishies2[j]--;
                }
            }
        }
        
        if(numOfDays - i > 6) {
            i += 5;
        }
        cout << "Number of fishies after " << i + 1 << " days: " << fishies1.size() + fishies2.size() << endl;
    }


    return 0;
}
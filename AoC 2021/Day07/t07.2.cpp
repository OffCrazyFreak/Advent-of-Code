#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (void){
    int numOfCrabs = 1000; // 1000
    int crabPosition;
    char delimiter;
    vector<int> crabsPositions;
    int fuelSum = 0;

    for(int i = 0; i < numOfCrabs; i++){
        cin >> crabPosition;
        crabsPositions.push_back(crabPosition);
        cin >> delimiter;
    }

    int crabsPositionsAverage = accumulate(crabsPositions.begin(), crabsPositions.end(), 0) / crabsPositions.size();
    cout << "Average: " << crabsPositionsAverage << endl;

    for(int pos : crabsPositions){
        // using Gauss' formula cause of traingular numbers - sum = n*(n+1)/2
        fuelSum += (abs(pos - crabsPositionsAverage) * (abs(pos - crabsPositionsAverage) + 1)) / 2; 
    }
    
    cout << "Fuel sum: " << fuelSum << endl;

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double median(vector<int> vec)
{
        typedef vector<int>::size_type vec_sz;

        vec_sz size = vec.size();
        if (size == 0)
                throw domain_error("median of an empty vector");

        sort(vec.begin(), vec.end());

        vec_sz mid = size/2;

        return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

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

    int crabsPositionsMedian = median(crabsPositions);
    cout << "Median: " << crabsPositionsMedian << endl;

    for(int pos : crabsPositions){
        fuelSum += abs(pos - crabsPositionsMedian);
    }
    
    cout << "Fuel sum: " << fuelSum << endl;

    return 0;
}
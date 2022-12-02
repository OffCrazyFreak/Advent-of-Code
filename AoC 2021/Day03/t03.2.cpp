#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int convert(long long int n) {
    int dec = 0, i = 0, rem;

    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        i++;
    }

    return dec;
}

int main (void){
    int inputs = 1000;
    int length = 12;
    long long int binaryNum;
    vector<int> v1;
    vector<int> v2;
    int frequency[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < inputs; i++){
        cin >> binaryNum;
        v1.push_back(convert(binaryNum));
        v2.push_back(convert(binaryNum));
    }

    // calculate O2
    for(int j = length - 1; v1.size() != 1; j--){
        // count the whether 1 or 0 appear more often on desired bit location
        for (int i : v1){
            // cout << (i >> j) % 2 << endl;
            if ((i >> j) % 2) // fetch desired bit
                frequency[j] += 1;
            else    
                frequency[j] -= 1;
        }
        // cout << "f[" << j << "]: " << frequency[j] << endl;
        frequency[j] >= 0 ? frequency[j] = 1 : frequency[j] = 0;

        for (int i = 0; i < v1.size(); i++){
            //cout << (v1[i] >> j) % 2 << endl;
            if ((v1[i] >> j) % 2 != frequency[j]){
                // cout << v1[i] << endl;
                v1.erase(v1.begin() + i); // erase the i-th element
                i--;
            }
        }
    }
    int O2Rating = v1[0];

    // calculate CO2
    for(int j = length - 1; v2.size() != 1; j--){
        // count the whether 1 or 0 appear more often on desired bit location
        for (int i : v2){
            // cout << (i >> j) % 2 << endl;
            if ((i >> j) % 2) // fetch desired bit
                frequency[j] += 1;
            else    
                frequency[j] -= 1;
        }
        // cout << "f[" << j << "]: " << frequency[j] << endl;
        frequency[j] >= 0 ? frequency[j] = 1 : frequency[j] = 0;
        
        for (int i = 0; i < v2.size(); i++){
            //cout << (v2[i] >> j) % 2 << endl;
            if ((v2[i] >> j) % 2 == frequency[j]){
                // cout << v2[i] << endl;
                v2.erase(v2.begin() + i); // erase the i-th element
                i--;
            }
        }
    }
    int CO2Rating = v2[0];

    cout << "Oxygen generator rating: " << O2Rating << " | CO2 scrubber rating: " << CO2Rating << endl;
    cout.precision(12);
    cout << "Life support rating: " << O2Rating * CO2Rating << endl;

    return 0;
}
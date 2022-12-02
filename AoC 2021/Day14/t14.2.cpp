#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct cPair{
    char cPair1;
    char cPair2;
    char insertionLetter;
};

// not working, too many steps - polymer too long
int main(void){
    int templateLength = 20; // 20
    int pairInsertions = 100; // 100
    int steps = 12; // 40
    vector<char> str;
    vector<cPair> insertionPairs;
    vector<char> chars;
    vector<long int> charsCount;

    // input template
    char c;
    for (int i = 0; i < templateLength; i++){
        cin >> c;
        str.push_back(c);
        // cout << str[i];    
    }

    // input character pairs and their insertion letter
    for (int i = 0; i < pairInsertions; i++){
        insertionPairs.push_back(cPair());
        cin >> insertionPairs[i].cPair1;
        cin >> insertionPairs[i].cPair2;
        for(int j = 0; j < 2; j++) // 2 because cin omits whitespaces
            cin >> c;
        cin >> insertionPairs[i].insertionLetter;
        
        // cout << "Pair: " << insertionPairs[i].cPair1 << insertionPairs[i].cPair2 << "=" << insertionPairs[i].insertionLetter << endl;
    }

    for(int i = 0; i < steps; i++){
        for(long int j = 0; j < str.size() - 1; j++){ // for each 2 characters
            for(int k = 0; k < insertionPairs.size(); k++){ // check if any of them match
                if(str[j] == insertionPairs[k].cPair1 && str[j + 1] == insertionPairs[k].cPair2){
                    str.insert(str.begin() + j+1, insertionPairs[k].insertionLetter);
                    j ++;
                    break;
                }
            }
        }
        
        /*cout << "After step " << i + 1 << ": "; 
        for(char c : str)
            cout << c;
        cout << endl;*/
    }

    bool characterAdded;
    for(char c : str){
        characterAdded = false;
        for(int i = 0; i < chars.size(); i++){
            if (c == chars[i]){
                // if letter already counted, increase its frequency
                charsCount[i]++;
                characterAdded = true;    
            }
        }

        if(!characterAdded){
            // otherwise add it to vector and count it
            chars.push_back(c);
            charsCount.push_back(1);
        }
    }

    int maxCount = 0, minCount = INT_MAX;
    for(int count : charsCount){
        maxCount = max(maxCount, count);
        minCount = min(minCount, count);
    }
    cout << maxCount << " - " << minCount << " = " << maxCount - minCount << endl;

    return 0;
}
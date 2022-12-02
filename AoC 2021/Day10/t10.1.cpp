#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int checkForErrors(string str, vector<char> *brackets){
    for(int j = 0; j < str.length(); j++){
        if(str.at(j) == '(' || str.at(j) == '{' || str.at(j) == '[' || str.at(j) == '<'){
            (*brackets).push_back(str.at(j));
            //cout << (*brackets).back();
        }else if(str.at(j) == ')'){
            if((*brackets).back() == '(')
                (*brackets).pop_back();
            else
                return 3;
        }else if(str.at(j) == '}'){
            if((*brackets).back() == '{')
                (*brackets).pop_back();
            else
                return 1197;
        }else if(str.at(j) == ']'){
            if((*brackets).back() == '[')
                (*brackets).pop_back();
            else
                return 57;
        }else if(str.at(j) == '>'){
            if((*brackets).back() == '<')
                (*brackets).pop_back();
            else
                return 25137;
        }
    }

    return 0; // if incomplete line
}

int main (void){

    int inputs = 94; // 94
    int points = 0;
    vector<char> brackets;
    string str;

    for (int i = 0; i < inputs; i++){
        cin >> str;
        points += checkForErrors(str, &brackets);
    }

    cout << "Points: " << points << endl;

    return 0;
}
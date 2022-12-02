#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long int scoreCompletion(string str, vector<char> *brackets){
    for(int j = 0; j < str.length(); j++){
        if(str.at(j) == '(' || str.at(j) == '{' || str.at(j) == '[' || str.at(j) == '<'){
            (*brackets).push_back(str.at(j));
            //cout << (*brackets).back();
        }else if(str.at(j) == ')'){
            if((*brackets).back() == '(')
                (*brackets).pop_back();
            else
                return 0;
        }else if(str.at(j) == '}'){
            if((*brackets).back() == '{')
                (*brackets).pop_back();
            else
                return 0;
        }else if(str.at(j) == ']'){
            if((*brackets).back() == '[')
                (*brackets).pop_back();
            else
                return 0;
        }else if(str.at(j) == '>'){
            if((*brackets).back() == '<')
                (*brackets).pop_back();
            else
                return 0;
        }
    }

    long int points = 0;

    while ((*brackets).size() > 0){
        points *= 5;
        
        if((*brackets).back() == '(')
            points += 1;
        else if((*brackets).back() == '[')
            points += 2;
        else if((*brackets).back() == '{')
            points += 3;
        else if((*brackets).back() == '<')
            points += 4;

        (*brackets).pop_back();
        // cout << points << endl;
        // cout << "Size: " <<(*brackets).size() << endl;
    }

    return points;
}

int main (void){

    int inputs = 94; // 94
    vector<long int> points;
    long int score;
    vector<char> brackets;
    string str;

    for (int i = 0; i < inputs; i++){
        cin >> str;
        score = scoreCompletion(str, &brackets);
        if(score != 0)
            points.push_back(score);
        else
            brackets.clear();
    }

    sort(points.begin(), points.end());

    // print out all the points
    /*for (long int x : points)
        cout << x << " ";
    */

    cout << "Points: " << points[points.size() / 2] << endl; // always an odd number of results

    return 0;
}
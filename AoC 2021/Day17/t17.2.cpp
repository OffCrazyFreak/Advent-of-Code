#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){

    int targetStartX;
    int targetEndX;
    int targetStartY;
    int targetEndY;
    char c;
    int trajectories = 0;

    //input data
    for(int i = 0; i < 13; i++){
        cin >> c;
    }
    cin >> targetStartX;
    for(int i = 0; i < 2; i++){
        cin >> c;
    }
    cin >> targetEndX;
    for(int i = 0; i < 3; i++){
        cin >> c;
    }
    cin >> targetStartY;
    for(int i = 0; i < 2; i++){
        cin >> c;
    }
    cin >> targetEndY;

    // cout << "Target: " << targetStartX << "..." << targetEndX << " | " << targetStartY << "..." << targetEndY << endl;  

    // calculate possible x speeds and number of steps for each
    int xDestination; // sum from 1 to xSpeed
    int xSpeed = targetEndX; // doesn't need to be seperate variable
    int completeStopXSpeeds = 0;
    map<int, int> xStepsFreqMap;
    while(xSpeed > 0){
        xDestination = 0;
        for(int i = xSpeed; i > 0; i--){
            xDestination += i;
            if(xDestination >= targetStartX && xDestination <= targetEndX){    
                // cout << "For speed " << xSpeed << ", steps needed: " << xSpeed - i + 1 << endl;

                map<int, int>::iterator it = xStepsFreqMap.find(xSpeed - i + 1);

                if(it != xStepsFreqMap.end()){ // if key already present in map
                    it->second++; // increment maps value for key i
                }else{
                    xStepsFreqMap.insert(make_pair(xSpeed - i + 1, 1));
                }

                if (i == 1) // for y-speeds higher than max num of x-steps
                    completeStopXSpeeds++;
            }
        }
        xSpeed--;
    }

    // print map keys and its values
    /* for(int i = 1; i <= xStepsFreqMap.size(); i++)
        cout << "Steps: " << i << " | Frequency: " << xStepsFreqMap[i] << endl; */

    //cout << xStepsFreqMap.size() << endl;
   
    
    // calculate possible y speeds and number of steps for each
    int yDestination; // sum from ySpeed to -ySpeed
    int ySpeed = -targetStartY + 1; // doesn't need to be seperate variable
    map<int, int> yStepsFreqMap;
    while(ySpeed >= targetStartY){
        yDestination = 0;
        // for ySpeed = 2, 6/7 steps is missing for some reason
        for(int i = ySpeed; i >= targetStartY; i--){
            yDestination += i;
            if(yDestination >= targetStartY && yDestination <= targetEndY){ 
                cout << "For speed " << ySpeed << ", steps needed: " << ySpeed - i + 1 << " | " << xStepsFreqMap[ySpeed - i + 1] << endl;
                if (xStepsFreqMap[ySpeed - i + 1] == 0)
                    trajectories += completeStopXSpeeds;
                
                    trajectories += xStepsFreqMap[ySpeed - i + 1];

                /* map<int, int>::iterator it = yStepsFreqMap.find(ySpeed - i + 1);

                if(it != yStepsFreqMap.end()){
                    // if key already present in map
                    it->second++; // increment maps value for key i
                }else{
                    yStepsFreqMap.insert(make_pair(ySpeed - i + 1, 1));
                } */
            }
        }
        ySpeed--;
    }

    // cout << xStepsFreqMap.size() << endl;
    cout << "Number of possible trajectories: " << trajectories << endl;

    return 0;
}


    // example code to add all elements of vector (keys) to map and their occurence (values)
    /*vector<int> xSpeedsSteps;
    xSpeedsSteps.push_back(1);
    xSpeedsSteps.push_back(2);
    xSpeedsSteps.push_back(1);
    map<int, int> xStepsFreqMap;
    for (int numOfSteps : xSpeedsSteps)
    {
        // check if key i exists in the map or not
        map<int, int>::iterator it = xStepsFreqMap.find(numOfSteps);
 
        // key already present on the map
        if (it != xStepsFreqMap.end()) {
            it->second++;    // increment map's value for key i
        }
        // key not found
        else {
            xStepsFreqMap.insert(make_pair(numOfSteps, 1));
        }
    }
    */
 
    // print map keys and its values
    /*for(auto &e : xStepsFreqMap) {
        cout << "Steps: " << e.first << " | Frequency: " << e.second << endl;
    }*/
    /*for(int i = 1; i <= xStepsFreqMap.size(); i++)
        cout << "Steps: " << i << " | Frequency: " << xStepsFreqMap[i] << endl;
    */

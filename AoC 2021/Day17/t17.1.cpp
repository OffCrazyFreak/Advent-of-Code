#include <iostream>

using namespace std;

int main(void){

    int targetStartX;
    int targetEndX;
    int targetStartY;
    int targetEndY;
    char c;

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
    
    /* not needed for part 1
    // calculate x speed
    int xDestination = 0;
    int xSpeed = 0;
    while(!(xDestination >= targetStartX && xDestination <= targetEndX))
        xDestination += ++xSpeed;
    
    cout << "X-speed: " << xSpeed << " | X-destination: " << xDestination << endl;
    */

    // max speed cannot be over or equal the target lower boundry
    // cause if it is, probe will jump over the target from y=0 to targetLowerBoundry+1
    int ySpeed = -targetStartY - 1; 
    int yHeight = ySpeed * (ySpeed + 1) / 2; // sum from 0 to ySpeed

    cout << "Max height with Y-speed of " << ySpeed << " is: " << yHeight << endl;
    


    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//reduce not working with bigger numbers
bool reduce(string *num){
    int nestLevel = 0;

    for(int i = 0; i < (*num).length(); i++){

        // keep track of nest level for explosions
        if((*num)[i] == '['){
            nestLevel++;
        }else if((*num)[i] == ']'){
            nestLevel--;
        }

        if((*num)[i] > '9' && (*num)[i] < '9' + 10){
            // split
            
            char leftOperand = ((*num)[i] - '0') / 2 + '0';
            char rightOperand = ceil((double) ((*num)[i] - '0') / 2) + '0';

            (*num).erase(i, 1);
            (*num).insert(i, (string) "[" + leftOperand + "," + rightOperand + "]");


            // cout << "Split:     " << *num << endl;

            return true;
        }else if(nestLevel > 4 && (*num)[i + 1] >= '0' && (*num)[i + 1] <= '9' && (*num)[i + 3] >= '0' && (*num)[i + 3] <= '9'){
            // explode
            int leftOperand = (*num)[i + 1] - '0';
            int rightOperand = (*num)[i + 3] - '0';

            // add right operand to regular number after it (if any)
            int index = i + 4;
            while(true){
                index++;

                if(index == (*num).length() || (((*num)[index] >= '0') && ((*num)[index] <= '9'))){
                    
                    // if regular number found
                    if(((*num)[index] >= '0') && ((*num)[index] <= '9'))
                        (*num)[index] += rightOperand;

                    break;
                }
            }

            // add left operand to regular number before it (if any)
            index = i;
            while(true){
                index--;

                if(index == 0 || (((*num)[index] >= '0') && ((*num)[index] <= '9'))){
                    
                    // if regular number found
                    if(((*num)[index] >= '0') && ((*num)[index] <= '9'))
                        (*num)[index] += leftOperand;

                    break;
                }
            }

            // turn pair into regular number 0
            (*num)[i] = '0';
            (*num).erase(i + 1, 4);

            // cout <<  "Explosion: " << *num << endl;

            return true;
        } 
        

    }

    return false;

}

void calculateMagnitude(string *num){
    bool noCalculations = false;
    while(!noCalculations){
        noCalculations = true;

        for(int i = 0; i < (*num).length(); i++){
            if((*num)[i + 2] == ',' && ( (*num)[i + 1] != '[') ){
                // turn pair into regular number magnitude
                (*num)[i] = ( (*num)[i + 1] - '0') * 3 + ( (*num)[i + 3] - '0') * 2 + '0';
                cout << (int) ((*num)[i] - '0') << endl; // goes over into negative...
                (*num).erase(i + 1, 4);
                
                noCalculations = false;

                cout << (*num) << endl;
                i++;
            }
        }
    }
}

int main(void){
    int snailFishNumbers = 1; // 100
    string num;
    string operand;

    for(int i = 0; i < snailFishNumbers; i++){
        if(i == 0){
            cin >> num;
        }else{
            cin >> operand;
            num = "[" + num + "," + operand + "]";
            // cout << "Number: " << num << endl;

            while(reduce(&num)); // reduce number
            // cout << "Reduced number: " << num << endl;
        }

    }

    cout << "Solution: " << num << endl;

    // calculate magnitude (not working)
    // calculateMagnitude(&num);

    cout << "Magnitude of number is: " << num << endl;
    
    return 0;
}
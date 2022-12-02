#include <iostream>
#include <cmath>

using namespace std;

int main (void){
    int inputs = 1000;
    int length = 12;
    long long binaryNum;
    int frequency[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int gammaRateDec = 0;

    for (int i = 0; i < inputs; i++){
        cin >> binaryNum;

        for(int j = 0; j < length; j++){

            if (binaryNum % 10 == 1)
                frequency[j] += 1;
            else    
                frequency[j] -= 1;
            binaryNum /= 10;
        }
    }

    for(int j = length - 1; j >= 0; j--){
        if (frequency[j] > 0)
            gammaRateDec += pow(2, j);
        
    }

    cout << "GammaRate: " << gammaRateDec << " EpsilonRate: " << pow(2, length) - gammaRateDec - 1 << endl;
    cout.precision(12);
    cout << "Power: " << gammaRateDec * (pow(2, length) - gammaRateDec - 1) << endl;

    return 0;
}
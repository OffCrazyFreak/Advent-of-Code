#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const char* hex_char_to_bin(char c){
    switch(c){
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }

    return "-1";
}

long long int binVec_to_dec(vector<bool> binNum){
    long long int value = 0;
    for(int i = 0; i < binNum.size(); i++){
        value += binNum[i] * pow(2, binNum.size() - 1 - i);
    }
    return value;
}

long long int parseLiteralValuePackets(vector<bool> packetBinary, int *index){
    
    vector<bool> binaryValueVec;
    
    while(true){
        // each number is 4 bits long + prefix bit
        for(int startIndex = ++(*index); *index < startIndex + 4; (*index)++)
            binaryValueVec.push_back(packetBinary[*index]);
        
        if(packetBinary[*index - 5] == 0){
            break; // if number has a prefix of 0, it is the last number
        }
    }
    
    long long int value = binVec_to_dec(binaryValueVec); // binVec_to_dec has to be declared before the function using it
    // cout << "Literal value in decimal: " << value << endl;

    return value;
}

long long int parsePacket(vector<bool> packetBinary, int *index){

    // get subpacket version and type ID
    int packetVersion = 0;
    for(int startIndex = *index; *index < startIndex + 3; (*index)++)
        packetVersion += packetBinary[*index] * pow(2, startIndex + 2 - (*index));
    
    int packetTypeID = 0;
    for(int startIndex = *index; *index < startIndex + 3; (*index)++)
        packetTypeID += packetBinary[*index] * pow(2, startIndex + 2 - *index);

    // cout << "Version: " << packetVersion << endl;
    // cout << "Type ID: " << packetTypeID << endl;

    if(packetTypeID == 4){
        // subpacket is a literal value
        return parseLiteralValuePackets(packetBinary, index);

    }else{
        // subpacket is operator

        int lengthTypeID = packetBinary[(*index)++]; // get length type ID
        // cout << "Length type ID: " << lengthTypeID << endl;
        
        vector<bool> subpacketsBinInfo;
        vector<long long int> subpacketsValues;
        if(lengthTypeID == 0){
            for(int startIndex = *index; *index < startIndex + 15; (*index)++)
                subpacketsBinInfo.push_back(packetBinary[*index]);
            int subpacketsLength = binVec_to_dec(subpacketsBinInfo);
            // cout << "Subpackets total length: " << subpacketsLength << endl;
            
            for(int startIndex = *index; *index < startIndex + subpacketsLength;)
                subpacketsValues.push_back(parsePacket(packetBinary, index));

        }else if(lengthTypeID == 1){
            for(int startIndex = *index; *index < startIndex + 11; (*index)++)
                subpacketsBinInfo.push_back(packetBinary[*index]);
            int subpacketsContainted = binVec_to_dec(subpacketsBinInfo);
            // cout << "Subpackets contained: " << subpacketsContainted << endl;

            for(int i = 0; i < subpacketsContainted; i++)
                subpacketsValues.push_back(parsePacket(packetBinary, index));
        }
        
        if(packetTypeID == 0){
            // sum values of subpackets
            long long int sum = 0;
            for(long long int value : subpacketsValues)
                sum += value;

            return sum;

        }else if(packetTypeID == 1){
            // multiply values of subpackets
            long long int product = 1;
            for(long long int value : subpacketsValues)
                product *= value;

            return product;

        }else if(packetTypeID == 2){
            // find minimal value of subpackets
            long long int min = subpacketsValues[0];
            for(long long int value : subpacketsValues)
                if(value < min)
                    min = value;

            return min;

        }else if(packetTypeID == 3){
            // find maximal value of subpackets
            long long int max = subpacketsValues[0];
            for(long long int value : subpacketsValues)
                if(value > max)
                    max = value;

            return max;

        }else if(packetTypeID == 5){
            // first subpacket is greater than second
            return subpacketsValues[0] > subpacketsValues[1];

        }else if(packetTypeID == 6){
            // first subpacket is less than second
            return subpacketsValues[0] < subpacketsValues[1];

        }else if(packetTypeID == 7){
            // first and second subpackets are equal
            return subpacketsValues[0] == subpacketsValues[1];
        }
    }

    // // skip extra zeros at the end of subpacket reach end of packet
    // while(packetBinary[*index] == 0){  // end of current subpacket
    //     if(*index == packet.length() * 4 - 1) // end of total packet
    //         break;
        
    //     (*index)++; // position index to start of next subpacket
    // }
    // // cout << index << endl;
    
    return -1;
}


int main(void){
    string packet;
    string byte;
    vector<bool> packetBinary;

    cin >> packet;
    for(char c : packet){
        byte = hex_char_to_bin(c);
        for(char bit : byte){
            packetBinary.push_back(bit - '0');
        }
    }

    // print packet in binary
    // for(bool bit : packetBinary){
    //     cout << bit;
    // }
    // cout << endl;

    int index = 0;
    cout << "Packet value: " << parsePacket(packetBinary, &index) << endl;
    
    return 0;
}
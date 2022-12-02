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

int binVec_to_dec(vector<bool> binNum){
    int value = 0;
    for(int i = 0; i < binNum.size(); i++){
        value += binNum[i] * pow(2, binNum.size() - 1 - i);
    }
    return value;
}

int parseLiteralValuePackets(vector<bool> packetBinary, int *index){
    
    vector<bool> binaryValueVec;
    
    while(true){
        // each number is 4 bits long + prefix bit
        for(int startIndex = ++(*index); *index < startIndex + 4; (*index)++)
            binaryValueVec.push_back(packetBinary[*index]);
        
        if(packetBinary[*index - 5] == 0){
            break; // if number has a prefix of 0, it is the last number
        }
    }
    
    int value = binVec_to_dec(binaryValueVec); // binVec_to_dec has to be declared before the function using it
    // cout << "Literal value in decimal: " << value << endl;

    return value;
}

void parsePacket(vector<bool> packetBinary, int *index, int *packetsVersionSum){

    // get subpacket version and type ID
    int packetVersion = 0;
    for(int startIndex = *index; *index < startIndex + 3; (*index)++)
        packetVersion += packetBinary[*index] * pow(2, startIndex + 2 - (*index));
    *packetsVersionSum += packetVersion;
    
    int packetTypeID = 0;
    for(int startIndex = *index; *index < startIndex + 3; (*index)++)
        packetTypeID += packetBinary[*index] * pow(2, startIndex + 2 - *index);

    // cout << "Version: " << packetVersion << endl;
    // cout << "Type ID: " << packetTypeID << endl;

    if(packetTypeID == 4){
        // subpacket is a literal value
        parseLiteralValuePackets(packetBinary, index);

    }else{
        // subpacket is operator

        int lengthTypeID = packetBinary[(*index)++]; // get length type ID
        // cout << "Length type ID: " << lengthTypeID << endl;
        
        vector<bool> subpacketsBinInfo;
        if(lengthTypeID == 0){
            for(int startIndex = *index; *index < startIndex + 15; (*index)++)
                subpacketsBinInfo.push_back(packetBinary[*index]);
            int subpacketsLength = binVec_to_dec(subpacketsBinInfo);
            // cout << "Subpackets total length: " << subpacketsLength << endl;
            
            for(int startIndex = *index; *index < startIndex + subpacketsLength;)
                parsePacket(packetBinary, index, packetsVersionSum);

        }else if(lengthTypeID == 1){
            for(int startIndex = *index; *index < startIndex + 11; (*index)++)
                subpacketsBinInfo.push_back(packetBinary[*index]);
            int subpacketsContainted = binVec_to_dec(subpacketsBinInfo);
            // cout << "Subpackets contained: " << subpacketsContainted << endl;

            for(int i = 0; i < subpacketsContainted; i++)
                parsePacket(packetBinary, index, packetsVersionSum);
        }
    }

    // // skip extra zeros at the end of subpacket reach end of packet
    // while(packetBinary[*index] == 0){  // end of current subpacket
    //     if(*index == packet.length() * 4 - 1) // end of total packet
    //         break;
        
    //     (*index)++; // position index to start of next subpacket
    // }
    // // cout << index << endl;
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
    int packetsVersionSum = 0;
    parsePacket(packetBinary, &index, &packetsVersionSum);

    cout << "Packet versions sum: " << packetsVersionSum << endl;
    
    return 0;
}
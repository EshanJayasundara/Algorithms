#include <iostream>
#include <vector>

using namespace std;


int fourBitBinaryToInt(string num) {
    int number = 0;
    for(int i=0; i<4; i++) {
        int pow = 1;
        if(num[i] == '1') {
            for(int j=0; j<3-i; j++) {
                pow *= 2;
            }
            number += pow;
            // cout << number << endl;
        }
    }
    return number;
}


int twoBitBinaryToInt(string num) {
    if(num == "00") return 0;
    else if(num == "01") return 1;
    else if(num == "10") return 2;
    else if(num == "11") return 3;
    return NULL;
}


string circularLeftShift(string array) {
    char temp = array[0];
    for (size_t i = 1; i < 28; i++)
    {
        array[i-1] = array[i];
    }
    array[27] = temp;
    return array;
}


// Initial permutation
vector<string> initialPermutation(string bin_plain_text) {
    int initial_permutation_box[] = {
        58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7
        };
    // cout<<plain_text[63]<<endl;
    char output_of_first_permutation[65];
    for (int i=0; i<64; i++)
    {
        output_of_first_permutation[i] = bin_plain_text[initial_permutation_box[i]-1];
    }
    // cout << output_of_first_permutation;
    string LPT = "";
    string RPT = "";
    for (size_t i = 0; i < 32; i++)
    {
        LPT += output_of_first_permutation[i];
    }
    for (size_t i = 32; i < 64; i++)
    {
        RPT += output_of_first_permutation[i];
    }

    vector<string> combined;
    combined.push_back(LPT);
    combined.push_back(RPT);

    return combined;
}


// Key transformation
string keyCompressionBox(string key) {
    int p_box[] = {
        14,17,11,24,1,5,3,28,15,6,21,10,
        23,19,12,4,26,8,16,7,27,20,13,2,
        41,52,31,37,47,55,30,40,51,45,33,48,
        44,49,39,56,34,53,46,42,50,36,29,32
    };
    char p_box_output[49];
    for (size_t i = 0; i < 48; i++)
    {
        p_box_output[i] = key[p_box[i]-1];
    }
    return p_box_output;
}


// Expand Right Plain Text
string expantionBox(string RPT) {
    char expanded_RPT[49];
    expanded_RPT[0] = RPT[31];
    expanded_RPT[47] = RPT[0];
    int n = 0;
    int j = 0;
    for (size_t i = 1; i < 47; i++)
    {
        if(i == 5+6*n || i == 6+6*n) {
            if(i == 6+6*n) {
                n+=1;
                expanded_RPT[i] = RPT[j-1];
                // cout << j-1 << "->" << i <<" ";
                continue;
            }
            if(i == 5+6*n) {
                expanded_RPT[i] = RPT[j];
                // cout << j << "->" << i << " ";
                continue;
            }
        }
        expanded_RPT[i] = RPT[j];
        // cout << j<< "~" << i <<" ";
        j++;
    }
    // for (size_t i = 0; i < 48; i++)
    // {
    //     cout << expanded_RPT[i];
    // }
    return expanded_RPT;
}


// s-box
string sBoxSubstitution(char xor_output[]) {
    vector<string> s_box[] = {
        {"0011", "1100", "0100", "0001", "0111", "1010", "1011", "0110", "1000", "0101", "0011", "1111", "1101", "0000", "1110", "1001"},
        {"1110", "1011", "0010", "1100", "0100", "0111", "1101", "0001", "0101", "0000", "1111", "1010", "0011", "1001", "1000", "0110"},
        {"0100", "0010", "0001", "1011", "1010", "1101", "0111", "1000", "1111", "1001", "1100", "0101", "0110", "0011", "0000", "1110"},
        {"1011", "1000", "1100", "0111", "0001", "1110", "0010", "1101", "0110", "1111", "0000", "1001", "1010", "0100", "0101", "0011"}
    };
    string sbox_output = "";
    for (size_t i = 0; i < 8; i++)
    {
        string col_num;
        string row_num;
        for (size_t j = i*6; j < 6*i+6; j++)
        {
            if(j%6 == 0 || j%6 == 5){
                row_num += xor_output[j];
            } else {
                col_num += xor_output[j];
            }
        }
        // cout << "row " << twoBitBinaryToInt(row_num) << endl;
        // cout << "col " << fourBitBinaryToInt(col_num) << endl;
        sbox_output += s_box[twoBitBinaryToInt(row_num)][fourBitBinaryToInt(col_num)];
    }
    // cout << sbox_output << endl;
    return sbox_output;
}


// p-box
string pBoxSubstitution(string sbox_output) {
    int p_box[] = {
        16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,
        2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25
        };
        char pbox_output[33];
    for (size_t i = 0; i < 32; i++)
    {
        pbox_output[i] = sbox_output[p_box[i]-1];
    }
    // for (size_t i = 0; i < 32; i++)
    // {
    //     cout << pbox_output[i];
    // }
    return pbox_output;
}

// rounds
vector<string> round(string LPT, string RPT, string expanded_RPT, string key) {
    char xor_output[49];

    // Key Transformation
    string compressed_key = keyCompressionBox(key);

    // Expansion permutation 2 (XOR the compressed key and expanded Right Plain Text)
    for (size_t i = 0; i < 48; i++)
    {
        if(compressed_key[i] == '0' && expanded_RPT[i] == '0') {
            xor_output[i] = '0';
        }
        else if(compressed_key[i] == '0' && expanded_RPT[i] == '1') {
            xor_output[i] = '1';
        }
        else if(compressed_key[i] == '1' && expanded_RPT[i] == '0') {
            xor_output[i] = '1';
        }
        else if(compressed_key[i] == '1' && expanded_RPT[i] == '1') {
            xor_output[i] = '0';
        }
    }

    // s-box
    string sbox_out = sBoxSubstitution(xor_output);

    // p-box
    string pbox_out = pBoxSubstitution(sbox_out);

    // final XOR with LPT
    string final_xor_output = "";
    for (size_t i = 0; i < 32; i++)
    {
        if(pbox_out[i] == '0' && LPT[i] == '0') {
            final_xor_output += '0';
        }
        else if(pbox_out[i] == '0' && LPT[i] == '1') {
            final_xor_output += '1';
        }
        else if(pbox_out[i] == '1' && LPT[i] == '0') {
            final_xor_output += '1';
        }
        else if(pbox_out[i] == '1' && LPT[i] == '1') {
            final_xor_output += '0';
        }
    }
    vector<string> cipher_text;
    cipher_text.push_back(RPT);
    cipher_text.push_back(final_xor_output);

    return cipher_text;
}

string bin(char c) {
    string s = "";
    while(c!=0) {
        s += to_string(c%2);
        c /= 2;
    }
    for(int i=0; s.length() != 8; i++) {
        s = '0' + s;
    }
    return s;
}

int main() {
    char plain_text[] = "STANDARD";

    // convert text into a char array
    string bin_plain_text = "";
    for(char c: plain_text) {
        bin_plain_text += bin(c); 
    }

    cout << "Plain Text : ";
    for (size_t i = 0; i < 64; i++)
    {
        cout << bin_plain_text[i];
    }
    cout << endl;

    vector<string> initial_permuted_txt = initialPermutation(bin_plain_text);

    string expanded_RPT = expantionBox(initial_permuted_txt[1]); // Expansion Permutation 1

    string keyH = "0101010101010101101001010101";
    string keyL = "0101010101010101010101010101";

    string key = circularLeftShift(keyH) + circularLeftShift(keyL);

    vector<string> DES1 = round(initial_permuted_txt[0], initial_permuted_txt[1], expanded_RPT, key);

    cout << "Cipher Text: ";
    for (size_t i = 0; i < 32; i++)
    {
        cout << DES1[0][i];
    }
    for (size_t i = 0; i < 32; i++)
    {
        cout << DES1[1][i];
    }

    return 0;
}
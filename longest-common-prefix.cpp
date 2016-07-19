//
//  main.cpp
//  Algorithm
//
//  Created by Joe McIlhargey on 7/13/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

string longestCommonPrefix(vector<string> &A) {

    if (A.size() == 1) {
        return A[0];
    }
    
    int maxLength = (int)A[0].length();
    
    for (string s : A) {
        if (s.length() < maxLength) {
            maxLength = (int)s.length();
        }
    }
    
    string longestStr = A[0].substr(0, maxLength);

    for (int i = 1; i < (int)A.size(); i++) {
        
        for (int j = 0; j < longestStr.length(); j++) {
 
            if (A[i].at(j) != longestStr.at(j)) {
                longestStr = longestStr.substr(0, j);
            }
        }
    }
    return longestStr;
}

int main() {
    
    vector<string> s = { "abcdefgh", "aefghijk", "abcefgh" };
    
    cout << longestCommonPrefix(s);
    
    return 0;
}

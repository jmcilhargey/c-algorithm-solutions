#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

string longestPalindrome(string A) {
    
    if (A.empty()) {
        return "";
    }
    
    if (A.length() == 1) {
        return A;
    }
    
    int start = 0, end = (int)A.length() - 1;
    int left, right;
    
    string longestPal = A.substr(0, 1);
    
    for (int i = 0; i <= end - 1; i++) {
        
        left = i;
        right = i;
        
        while (left >= start && right <= end && A.at(left) == A.at(right)) {
            left--;
            right++;
        }
        
        if (right - left - 1 > longestPal.length()) {
            longestPal = A.substr(left + 1 , right - left - 1);
        }
        
        left = i;
        right = i + 1;

        while (left >= start && right <= end && A.at(left) == A.at(right)) {
            left--;
            right++;
        }
        
        if (right - left - 1 > longestPal.length()) {
            longestPal = A.substr(left + 1 , right - left - 1);
        }
    }

    return longestPal;
}

int main() {
    
    cout << longestPalindrome("abbcccbbbcaaccbababcbcabca");
    
    return 0;
}

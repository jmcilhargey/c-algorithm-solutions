#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findLPSArray(const string &needle, int needleLength, int *longestPrefixSuffix) {
    
    int length = 0;
    int i;
    
    longestPrefixSuffix[0] = 0;
    i = 1;

    while (i < needleLength) {
        if (needle[i] == needle[length]) {
            length++;
            longestPrefixSuffix[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = longestPrefixSuffix[length - 1];
            } else {
                longestPrefixSuffix[i] = 0;
                i++;
            }
        }
    }
}

int strStr(const string &haystack, const string &needle) {
    
    int needleLength = (int)needle.length();
    int haystackLength = (int)haystack.length();

    int *longestPrefixSuffix = new int [needle.length()];
    int j = 0;
    
    findLPSArray(needle, needleLength, longestPrefixSuffix);
    
    int i = 0;
    while (i < haystackLength) {
        
        if (needle[j] == haystack[i]) {
            j++;
            i++;
        }
        
        if (j == needleLength) {
            return i - j;
        }
        
        else if (i < haystackLength && needle[j] != haystack[i]) {
            
            if (j != 0) {
                j = longestPrefixSuffix[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    return -1;
}

int main() {
    string txt = "";
    string pat = "t";
    cout << strStr(txt, pat);
    return 0;
}
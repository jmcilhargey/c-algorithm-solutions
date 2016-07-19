#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

vector<string> fullJustify(vector<string> &A, int B) {
    
    int lettersSoFar = 0;
    int extraSpaces = 0;
    vector<string> justifiedText;
    vector<string> currentLine;
    int numOfWords = 0;
    string buildLine = "";
    
    if (A.size() == 0 || B < 1) {
        return justifiedText;
    }
    
    int i = 0;
    
    while (i < A.size()) {
        
        while (lettersSoFar + numOfWords <= B && i < A.size()) {
            
            if (lettersSoFar + A[i].length() + numOfWords > B) {
                break;
            }
            
            lettersSoFar += A[i].length();
            i++;
            numOfWords++;
        }
        
        for (int j = i - numOfWords; j < i; j++) {
            currentLine.push_back(A[j]);
        }
        
        extraSpaces = B - lettersSoFar;
        
        while (extraSpaces > 0) {
            
            int k = 0;
            
            for ( ; k < numOfWords - 1 && extraSpaces > 0; k++, extraSpaces--) {
                currentLine[k].append(" ");
            }
            
            if (numOfWords == 1 || i == A.size()) {
                currentLine[k].append((string (extraSpaces, ' ')));
                extraSpaces = 0;
            }
        }
        
        for (string word : currentLine) {
            buildLine += word;
        }
        
        justifiedText.push_back(buildLine);
        
        currentLine.clear();
        buildLine = "";
        numOfWords = 0;
        lettersSoFar = 0;
    }
    return justifiedText;
}

int main() {
    
    vector<string> s1 = { "This", "is", "an", "example", "of", "text", "justification." };
    vector<string> s2 = { "What", "must", "be", "shall", "be." };
    
    vector<string> justified = fullJustify(s1, 16);
    
    for (string s : justified) {
        cout << s << endl;
    }
    
    return 0;
}

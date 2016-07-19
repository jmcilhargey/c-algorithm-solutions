#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

vector<int> searchRange(const vector<int> &A, int B) {
    
    int endIndex = (int)A.size();
    int startIndex = -1;
    int targetStart = -1;
    int targetEnd = -1;
    bool found = false;
    
    vector<int> range(2, -1);
    
    if (A.size() == 1) {
        range[0] = 0;
        range[1] = 0;
        return range;
    }
    
    while (endIndex > startIndex + 1 && !found) {
        
        int middleIndex = (endIndex - startIndex) / 2 + startIndex;
        int middleVal = A[middleIndex];
        
        if (middleVal > B) {
            endIndex = middleIndex;
        } else if (middleVal < B) {
            startIndex = middleIndex;
        } else {
            found = true;
            targetStart = middleIndex;
            targetEnd = middleIndex;
            
            while (A[targetStart - 1] == B && targetStart > startIndex) {
                targetStart--;
            }
            range[0] = targetStart;
            while (A[targetEnd + 1] == B && targetStart < endIndex) {
                targetEnd++;
            }
            range[1] = targetEnd;
        }
    }
    return range;
}

int main() {
    
    ;
    
    vector<int> v = searchRange(vector<int> { 8, 8, 8, 8, 9, 10, 13, 17, 20 } ,8);
    
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}

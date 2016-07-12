#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(const vector<int> &A) {
    
    vector<int> sumSoFar(A.size());
    sumSoFar[0] = A[0];
    int maxVal = A[0];
    
    for (int i = 1; i < A.size(); i++) {
        sumSoFar[i] = max(A[i], sumSoFar[i - 1] + A[i]);
        maxVal = max(sumSoFar[i], maxVal);
    }
    return maxVal;
}

int main() {
    
    vector<int> v = { -2,1,-3,4,-1,2,1,-5,4 };
    
    cout << maxSubArray(v);
    
    return 0;
}
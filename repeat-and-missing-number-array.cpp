#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    
    vector<int> intsPair(2, 0);
    
    int n = (int)A.size();
    
    int xorSum = A[0];
    
    for (int i = 1; i < n; i++) {
        xorSum ^= A[i];
    }
    for (int j = 1; j <= n; j++) {
        xorSum ^= j;
    }
    
    int rightBit = xorSum & ~(xorSum - 1);
    
    for (int i = 0; i < n; i++) {
        if (A[i] & rightBit) {
            intsPair[0] ^= A[i];
        } else {
            intsPair[1] ^= A[i];
        }
    }
    
    for (int j = 1; j <= n; j++) {
        if (j & rightBit) {
            intsPair[0] ^= j;
        } else {
            intsPair[1] ^= j;
        }
    }
    
    bool swap = false;
    
    for (int i = 0; i < n && !swap; i++) {
        if (A[i] == intsPair[1]) {
            iter_swap(intsPair.begin(), intsPair.begin() + 1);
            swap = true;
        }
    }
    
    return intsPair;
}

int main() {
    
    vector<int> v = { 3, 1, 2, 5, 3 };
    
    vector<int> v2 = repeatedNumber(v);
    
    for (int num : v2) {
        cout << num << endl;
    }
    
    return 0;
}
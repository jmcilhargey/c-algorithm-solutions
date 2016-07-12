#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void setZeroes(vector<vector<int> > &A) {
    
    bool firstRowZero = false;
    bool firstColZero = false;
    
    for (int i = 0; i < A[0].size() && !firstRowZero; i++) {
        if (A[0][i] == 0) {
            firstRowZero = true;
        }
    }
    for (int j = 0; j < A.size() && !firstColZero; j++) {
        if (A[j][0] == 0) {
            firstColZero = true;
        }
    }
    
    for (int i = 1; i < A.size(); i++) {
        for (int j = 1; j < A[0].size(); j++) {
            if (A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    // Go through row to see if any cols need to be zeroed
    for (int j = 1; j < A[0].size(); j++) {
        if (A[0][j] == 0) {
            for (int i = 0; i < A.size(); i++) {
                A[i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < A.size(); i++) {
        if (A[i][0] == 0) {
            for (int j = 0; j < A[0].size(); j++) {
                A[i][j] = 0;
            }
        }
    }
    // Set rows and cols to 0 if 0 was found
    if (firstRowZero) {
        for (int i = 0; i < A[0].size(); i++) {
            A[0][i] = 0;
        }
    }
    
    if (firstColZero) {
        for (int j = 0; j < A.size(); j++) {
            A[j][0] = 0;
        }
    }
};

int main() {
    
    vector<vector<int>> v = { {1, 0, 1}, { 1, 1, 1 }, {1, 1, 1} };
    
    setZeroes(v);
    
    for (vector<int> row : v) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
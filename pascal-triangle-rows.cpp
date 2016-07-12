#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > generate(int A) {
    
    vector<vector<int>> triangle;
    
    if (A == 0) {
        return triangle;
    }
    triangle.push_back(vector<int> { 1 });
    if (A == 1) {
        return triangle;
    }
    triangle.push_back(vector<int> { 1, 1 });
    if (A == 2) {
        return triangle;
    }
    
    for (int i = 2; i < A; i++) {
        vector<int> rowVals(i + 1, 1);
        for (int j = 1; j < i; j++) {
            rowVals[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(rowVals);
    }
    return triangle;
}


int main() {
    
    vector<vector<int>> tri = generate(10);
    
    for (vector<int> row : tri) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>> &A) {

    int height = (int)A.size() - 1;

    for (int layer = 0; layer < A.size() / 2; layer++) {
    
        for (int j = layer; j < height - layer; j++) {
        
            int temp = A[layer][j];
            A[layer][j] = A[height - j][layer];
            A[height - j][layer] = A[height - layer][height - j];
            A[height - layer][height - j] = A[j][height - layer];
            A[j][height - layer] = temp;
        }
    }
}

int main() {
    
    vector<vector<int>> v = {
                               { 1, 2, 3, 4 },
                               { 5, 6, 7, 8 },
                               { 9, 10, 11, 12 },
                               { 13, 14, 15, 16 }
                            };
    
    rotate(v);
    
    for (vector<int> i : v) {
        for (int n : i) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    return 0;
}

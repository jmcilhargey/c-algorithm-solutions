#include <iostream>
#include <vector>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(int A) {
    
    int placeHolder = 1;
    int lastNum, firstNum;
    
    while (A / placeHolder >= 10) {
        placeHolder *= 10;
    }
    
    while (A > 0) {
        
        lastNum = A / placeHolder;
        firstNum = A % 10;
        
        if (firstNum != lastNum) {
            return false;
        }
        
        A = A % placeHolder / 10;
        placeHolder /= 100;
    }
    return true;
}

int main() {
    
    cout << isPalindrome(16761);
    
    return 0;
}
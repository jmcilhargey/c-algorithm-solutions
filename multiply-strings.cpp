#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string multiply(string A, string B) {
    
    string total = "";
    
    if (A == "0" || B == "0") {
        return "0";
    }
    const int maxDigits = (int)A.length() + (int)B.length();
    vector<int> sumOfEach(maxDigits, 0);
    
    for (int i = (int)A.length() - 1; i >= 0; i--) {
        for (int j = (int)B.length() - 1; j >= 0; j--) {
            sumOfEach[maxDigits - 1 - i - j] += (A.at(i) - '0') * (B.at(j) - '0');
        }
    }
    
    int carry = 0, currNum;
    
    for (int k = 0; k < sumOfEach.size(); k++) {
        
        currNum = sumOfEach[k] + carry;
        carry = currNum / 10;
        
        total += to_string(currNum % 10);
    }

    if (carry > 0) {
        total += to_string(carry);
    }
    
    total = string(total.rbegin(), total.rend());
    
    while (total.at(0) == '0') {
        total = total.substr(1);
    }
    
    return total.substr(0, total.length() - 1);
}

int main() {
    
    string num1 = "478561";
    string num2 = "31635";
    
    cout << multiply(num1, num2) << endl;
    
    return 0;
}
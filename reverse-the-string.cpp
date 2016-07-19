void reverseWords(string &A) {
    
    int i = 0;
    string word = "";
    vector<string> phrase;
    
    while (A.length() - 1 >= i) {
        
        if (!isspace(A.at(i)) ) {
            word += A.at(i);
        }
        
        if ((isspace(A.at(i)) || i == A.length() - 1) && word.length() > 0) {
            phrase.push_back(word);
            word = "";
        }
        i++;
    }
    A = "";
    
    reverse(phrase.begin(), phrase.end());
    
    for (string w : phrase) {
        A += w + " ";
    }
    A = A.substr(0, A.length() - 1);
}

int main() {
    
    string txt = "h";
    
    reverseWords(txt);;
    
    cout << txt;
    
    return 0;
}
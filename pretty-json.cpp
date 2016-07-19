#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

vector<string> prettyJSON(string A) {
    
    vector<string> output;
    string line;
    int indent = 0;
    int i = 0;
    
    if (A.length() == 0) {
        return output;
    }
    
    while (i < A.length()) {
        
        while (isspace(A.at(i))) {
            i++;
        }
        
        char current = A.at(i);
        
        switch(current) {
                
            case '{':
            case '[':
                
                output.push_back(line + string(1, current));
                indent++;
                line = string(indent, '\t');
                i++;
                break;
                
            case '}':
            case ']':
                i++;
                if (i < A.length() && A.at(i) == ',') {
                    output.push_back(line + string(1, current) + ',');
                    i++;
                } else {
                    output.push_back(line + string(1, current));
                    if (indent > 0) {
                        indent--;
                    }
                }
                
                line = string(indent, '\t');

                break;
                
            case ':':
                line += current;
                i++;
                if (A.at(i) == '{' || A.at(i) == '[') {
                    output.push_back(line);
                    line = string(indent, '\t');
                }
                break;
                
            case ',':
                
                line += current;
                output.push_back(line);
                i++;
                line = string(indent, '\t');
                break;
                
            default:
                
                line += current;
                i++;
                if (A.at(i) == '}' || A.at(i) == ']') {
                    output.push_back(line);
                    if (indent > 0) {
                        indent--;
                    }
                    
                    line = string(indent, '\t');
                }
                break;
        }
    }
    
    return output;
}

int main() {
    
    string s1 = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";
    string s2 = "[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";
    string s3 = "{\"attributes\":[{\"nm\":\"ACCOUNT\",\"lv\":[{\"v\":{\"Id\":null,\"State\":null},\"vt\":\"java.util.Map\",\"cn\":1}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":13585},{\"nm\":\"PROFILE\",\"lv\":[{\"v\":{\"Party\":null,\"Ads\":null},\"vt\":\"java.util.Map\",\"cn\":2}],\"vt\":\"java.util.Map\",\"status\":\"SUCCESS\",\"lmd\":41962}]}";
    
    vector<string> v = prettyJSON(s1);
    
    for (string s : v) {
        cout << s << endl;
    }
    
    return 0;
}
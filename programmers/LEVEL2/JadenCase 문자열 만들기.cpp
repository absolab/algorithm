#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(string s) {

    string answer = "";
    bool is_first = true;
    for (int i=0; i<s.size(); ++i) {
        char c = s[i];

        if (is_first) {
            is_first = false;
            if (c >= 'a' && c <= 'z') { c = toupper(c); }
        } else {
            if (c >= 'A' && c <= 'Z') { c = tolower(c); }
        }

        if (c == ' ') is_first = true;

        answer.push_back(c);
    }    

    return answer;
}

int main(void) {

    string s = "3people unFollowed me";
    string result = solution(s);

    cout << result << endl;

 
    return 0;
}
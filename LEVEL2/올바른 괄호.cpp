#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool solution(string s) {

    bool answer = true;

    vector<char> v;

    for (int i=0; i<s.size(); ++i) {

        char c = s[i];

        if (c == '(') v.push_back(c);
        else {
            if (v.size() == 0) return false;
            if (v.back() == '(') v.pop_back();
            else return false;
        }
    }

    if (v.size() == 0) return true;
    else return false;

    return true;
}

int main(void) {

    string s = "()()";

    bool result = solution(s);    
    cout << result << endl;

    return 0;
}
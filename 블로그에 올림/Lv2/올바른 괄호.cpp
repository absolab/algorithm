#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool solution(string s) {

    bool answer = true;

    // 스택
    vector<char> v;

    for (int i=0; i<s.size(); ++i) {

        char c = s[i];

        if (c == '(') v.push_back(c);
        else {
            // 비어있는데 ')'가 들어있으면 잘못된 괄호
            if (v.size() == 0) return false;
            if (v.back() == '(') v.pop_back();
            else return false;
        }
    }

    // 순회가 끝나고 스택이 비어있으면 올바른 괄호
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
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(string s) {

    int answer = 0;

    for (int i=0; i<s.size(); ++i) {
        
        vector<char> v;

        for (int j=0; j<s.size(); ++j) {
            if (v.size() == 0) {
                v.push_back(s[j]);
                continue;
            }

            char pre_c = v.back();
            char c = s[j];

            if (pre_c == '(' && c == ')') v.pop_back();
            else if (pre_c == '{' && c == '}') v.pop_back();
            else if (pre_c == '[' && c == ']') v.pop_back();
            else v.push_back(c);
        }

        if (v.size() == 0) answer++;
        char c = s[0];
        s = s.substr(1,s.size());
        s += c;
    }

    return answer;
}

int main(void) {

    string s = "[](){}";
    int result = solution(s);

    cout << result << endl;

    return 0;
}
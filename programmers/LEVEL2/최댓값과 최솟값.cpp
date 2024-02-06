#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(string s) {

    string answer = "";

    long long min_num = LONG_LONG_MAX;
    long long max_num = LONG_LONG_MIN;
    
    vector<string> v;

    int start = 0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i] == ' ') {
            v.push_back(s.substr(start, i-start));
            start = i+1;
        }
    }
    v.push_back(s.substr(start, s.size()-start));

    for (int i=0; i<v.size(); ++i) {
        long long num = stoi(v[i]);

        min_num = min(min_num, num);
        max_num = max(max_num, num);
    }

    answer += to_string(min_num);
    answer.push_back(' ');
    answer += to_string(max_num);

    return answer;
}

int main(void) {

    string s = "1 2 3 4";
    string result = solution(s);

    cout << result << endl;

    return 0;
}
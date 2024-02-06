#include <string>
#include <vector>

#include <iostream>
using namespace std;

string solution(string s) {

    string answer = "";

    if (s.size() % 2 == 0) {
        answer += s.substr(s.size()/2-1, 2);
    } else {
        answer += s[s.size()/2];
    }

    return answer;
}

int main(void) {

    string s = "qwer";

    string result = solution(s);

    cout << result << endl;

    return 0;
}
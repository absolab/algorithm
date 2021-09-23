#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {

    string answer = "";

    for (int i=0; i<s.size(); ++i) {

        if (s[i] == ' ') {

            answer += ' ';

        } else if (s[i] >= 'a' && s[i] <= 'z') {

            char c = s[i] - 'a' + n;

            c = (c % 26) + 'a';

            answer += c;
            
        } else { // s[i] >= 'A' && s[i] <= 'Z'

            char c = s[i] - 'A' + n;

            c = (c % 26) + 'A';

            answer += c;

        }
    }

    return answer;
}

int main(void) {

    string s = "AB";
    int n = 1;

    string result = solution(s, n);

    cout << result << endl;

    return 0;
}
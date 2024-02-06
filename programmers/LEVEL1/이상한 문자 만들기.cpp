#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {

    string answer = "";
    int index = 0;

    for (int i=0; i<s.size(); ++i) {

        char c = s[i];

        if (c == ' ') {
            index = 0;
            answer += c;
        } else {

            if (index++ % 2 == 0) {
                answer += toupper(c);
            } else {
                answer += tolower(c);
            }
        }
    }

    return answer;
}

int main(void) {

    string s = "try hello world";
    string result = solution(s);

    cout << result << endl;

    return 0;
}
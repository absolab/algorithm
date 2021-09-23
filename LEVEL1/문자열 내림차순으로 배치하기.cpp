#include <string>
#include <vector>

#include <iostream>
using namespace std;

string solution(string s) {

    string answer = "";

    for (int i=0; i<s.size(); ++i) {

        unsigned char c = 0;
        int pos = 0;

        for (int j=0; j<s.size(); ++j) {

            if (c < s[j]) {

                c = s[j];
                pos = j;
            }
        }

        answer += c;
        s[pos] = ' ';
    }

    return answer;
}

int main(void) {

    string s = "Zbcdefg";

    string result = solution(s);

    cout << result << endl;

    return 0;
}
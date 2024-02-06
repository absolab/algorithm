#include <string>
#include <vector>

#include <iostream>
using namespace std;

bool solution(string s) {

    bool answer = true;

    if (s.size() != 4 && s.size() != 6) {

        answer = false;

    } else {
        
        for (int i=0; i<s.size(); ++i) {

            char c = s[i];

            if (c < '0' || c > '9') {
                answer = false;
                break;
            }
        }

    }

    return answer;
}

int main(void) {

    string s = "a234";

    bool result = solution(s);

    cout << result << endl;

    return 0;
}
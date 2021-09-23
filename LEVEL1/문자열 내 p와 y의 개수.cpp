#include <string>
#include <iostream>

#include <iostream>

using namespace std;

bool solution(string s) {

    bool answer = true;

    int p_count = 0;
    int y_count = 0;

    for (int i=0; i<s.size(); ++i) {
        if (s[i] == 'p' || s[i] == 'P') {
            ++p_count;
        }

        if (s[i] == 'y' || s[i] == 'Y') {
            ++y_count;
        }
    }

    if (p_count == y_count) answer = true;
    else answer = false;

    return answer;
}

int main(void) {

    string s = {"pPoooyY"};

    bool result = solution(s);

    cout << result << endl;

    return 0;
}
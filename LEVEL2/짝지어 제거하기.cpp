#include <vector>
#include <string>
#include <iostream>

using namespace std;

char cs[1000000];
int idx = 0;

int solution(string s) {

    int answer = 0;

    cs[0] = s[0];

    for (int i=1; i<s.size(); ++i) {
        if (idx == -1) {
            cs[++idx] = s[i];
        } else if (cs[idx] == s[i]) {
            --idx;
        } else {
            cs[++idx] = s[i];
        }
    }

    if (idx == -1) answer = 1;

    return answer;
}

int main(void) {

    string s = "abbcdaadca";

    int result = solution(s);
  
    cout << result << endl;

    return 0;
}
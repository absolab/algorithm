#include <vector>
#include <string>
#include <iostream>

using namespace std;

char cs[1000000];       // 스택
int idx = 0;            // top의 인덱스

int solution(string s) {

    int answer = 0;

    // 초기값 지정
    cs[0] = s[0];

    for (int i=1; i<s.size(); ++i) {

        // 스택이 비어있으면 push
        if (idx == -1) {

            cs[++idx] = s[i];

        // 스택에 들어있는 값과 같으면 pop
        } else if (cs[idx] == s[i]) {

            --idx;

        // 스택에 들어있는 값과 다르면 push
        } else {

            cs[++idx] = s[i];
        }
    }

    // 스택이 비어있으면 1 반환
    if (idx == -1) answer = 1;

    return answer;
}

int main(void) {

    string s = "abbcdaadca";

    int result = solution(s);
  
    cout << result << endl;

    return 0;
}
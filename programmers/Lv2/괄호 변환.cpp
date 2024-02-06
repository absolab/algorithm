#include <vector>
#include <string>
#include <iostream>

using namespace std;

string separate(string p) {

    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
    if (p.size() == 0) {
        return "";
    }

    string u = "";      // 균형잡힌 괄호 문자열
    string v = "";      // 빈 문자열이 될 수 있음

    // 2. 문자열 w(여기선 p)를 u와 v로 분리
    int score = 0;
    for (int i=0; i<p.size(); ++i) {
        if (p[i] == '(') {
            score += 1;
        } else {
            score -= 1;
        }

        // 스코어가 0인 경우 '('의 수와 ')'의 수가 같다는 의미
        if (score == 0) {
            u = p.substr(0, i + 1);
            v = p.substr(i+1, p.size()-i);
            break;
        }
    }

    // 3. u가 올바른 괄호 문자열인지 확인
    score = 0;
    bool is_correct_str = true;
    for (int i=0; i<u.size(); ++i) {
        if (u[i] == '(') {
            score += 1;
        } else {
            score -= 1;
        }
        
        // 스코어가 음수가 되는 순간 이 문자열은 잘못됨
        if (score < 0) {
            is_correct_str = false;
        }
    }

    string w = "";
    // 3. u가 올바른 괄호 문자열인 경우 v에 대해 1단계부터 수행
    if (is_correct_str == true) {
        w += u;
        w += separate(v);

    // 4. 문자열 u가 올바른 괄호 문자열이 아닌 경우
    } else {
        w += '(';               // 4-1
        w += separate(v);       // 4-2
        w += ')';               // 4-3
        // 4-4
        for (int i=1; i<u.size()-1; ++i) {
            if (u[i] == '(') {
                w += ')';
            } else {
                w += '(';
            }
        }
    }

    // 3-1, 4-5. 생성된 문자열을 반환
    return w;
}

string solution(string p) {
    
    string answer = "";

    answer = separate(p);
    
    return answer;
}

int main(void) {

    string p = "()))((()";
    string result = solution(p);

    cout << result << endl;

    return 0;
}
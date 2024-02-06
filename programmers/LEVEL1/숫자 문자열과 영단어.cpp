#include <iostream>
using namespace std;

// 제출할 부분

int solution(const char* s) {

    int answer = 0;
    int num = 0;
    for (int i=0; s[i] != '\0'; ++i) {

        // 숫자인지 확인
        if (s[i] >= '0' && s[i] <= '9') {
            
            num = s[i] - '0';

        } else {
            // 어떤 숫자의 문자인지 확인
            if (s[i] == 'z') {

                i += 3;
                num = 0;    

            } else if (s[i] == 'o') {

                i += 2;
                num = 1;

            } else if (s[i] == 't') {

                if (s[i+1] == 'w') {

                    i += 2;
                    num = 2;

                } else {

                    i += 4;
                    num = 3;

                }

            } else if (s[i] == 'f') {

                if (s[i+1] == 'o') {

                    i += 3;
                    num = 4;

                } else {

                    i+= 3;
                    num = 5;

                }

            } else if (s[i] == 's') {

                if (s[i+1] == 'i') {

                    i += 2;
                    num = 6;

                } else {

                    i += 4;
                    num = 7;

                }

            } else if (s[i] == 'e') {

                i += 4;
                num = 8;

            } else {

                i += 3;
                num = 9;

            }
        }

        answer *= 10;
        answer += num;
    }


    return answer;
}

int main() {

    cout << solution("123") << endl;

    return 0;
}


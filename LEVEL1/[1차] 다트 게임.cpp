#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {

    int answer = 0;

    int scores[3] = {0, };
    int score_pos = 0;

    for (int i=0; i<dartResult.length(); ++i) {
        
        char c = dartResult[i];

        if (c >= '0' && c <= '9') {

            if (dartResult[i+1] == '0') {

                scores[score_pos++] = 10;
                ++i;
            } else {

                scores[score_pos++] = (int)(c - '0');
            }


        } else if (c == '*') {

            scores[score_pos-1] *= 2;

            if (score_pos != 1) {
                scores[score_pos-2] *= 2;
            }

        } else if (c == '#') {

            scores[score_pos-1] *= -1;

        } else if (c == 'S') {

            //

        } else if (c == 'D') {

            scores[score_pos-1] *= scores[score_pos-1];

        } else { // c == 'T'
            scores[score_pos-1] = scores[score_pos-1] * scores[score_pos-1] * scores[score_pos-1];
        }
    }

    answer = scores[0] + scores[1] + scores[2];

    return answer;
}

int main(void) {

    string dartResult = "1S2D*3T";

    int result = solution(dartResult);

    cout << result << endl;

    return 0;
}
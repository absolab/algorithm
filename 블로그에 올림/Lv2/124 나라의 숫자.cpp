#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(int n) {

    string answer = "";
    int triad[19];

    // 3진수로 변환
    int div = 387420489;    // 3^18 = 387,420,489
    bool is_first_num = true;
    int first_num_pos = 0;
    for (int i=0; i<19; ++i) {

        triad[i] = n / div;

        if (triad[i] != 0 && is_first_num) {
            is_first_num = false;
            first_num_pos = i;
        }

        n %= div;
        div /= 3;
    }

    // 124 진수로 변환
    for (int i=18; i>first_num_pos; --i) {

        // 0일 경우 앞에서 숫자를 당긴 후 4로 변환한다.
        if (triad[i] == 0 && i != 0) {            
            triad[i-1]--;
            triad[i] = 4;
        
        // 이전 자릿수에서 1을 당겨오는 바람에 -1이 된 경우엔 앞에서 당긴 후 2로 변환한다
        } else if (triad[i] == -1 && i != 0) {
            triad[i-1]--;
            triad[i] = 2;
        } 
    }

    for (int i=0; i<19; ++i) {
        if (triad[i] != 0) {
            answer += '0' + triad[i];
        }
    }

    return answer;
}

int main(void) {

    int n = 9;

    string result = solution(n);

    cout << result << endl;

    return 0;
}
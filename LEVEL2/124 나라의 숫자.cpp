#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(int n) {

    string answer = "";
    int triad[19];
    // 3^18 = 387,420,489
    int div = 387420489;
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

    for (int i=18; i>first_num_pos; --i) {
        if (triad[i] == 0 && i != 0) {
            
            triad[i-1]--;
            triad[i] = 4;
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
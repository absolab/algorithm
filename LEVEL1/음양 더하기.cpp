#include <iostream>
using namespace std;

int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int answer = 0;

    for (int i=0; i<absolutes_len; ++i) {
        if (signs[i]) {
            answer += absolutes[i];
        } else {
            answer -= absolutes[i];
        }
    }

    return answer;
}

int main(void) {

    int absolutes[] = {4, 7, 12};
    bool signs[] = {true, false, true};
    cout << solution(absolutes, 3, signs, 3) << endl;
}
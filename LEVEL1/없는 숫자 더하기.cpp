#include <iostream>
using namespace std;

int solution(int numbers[], size_t numbers_len) {

    int answer = 45;

    for (int i=0; i<numbers_len; ++i) {
        answer -= numbers[i];
    }

    return answer;

}

int main(void) {

    int numbers[] = {1,2,3,4,6,7,8,0};
    cout << solution(numbers, 8) << endl;
}
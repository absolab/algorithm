#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {

    int answer = 0;

    const int max = 43046721;
    int ternary[17] = {0,};

    int temp = max;
    for (int i=0; i<17; ++i) {
        
        if (temp <= n) {
            ternary[i] = n / temp;
            n %= temp;
        }

        temp /= 3;
    }

    int first = 0;
    for (int i=0; i<17; ++i) {
        if (ternary[i] != 0) {
            first = i;
            break;
        }
    }

    temp = 1;
    for (int i=first; i<17; ++i) {
        answer += ternary[i] * temp;
        temp *= 3;
    }

    return answer;
}

int main(void) {

    int n = 45;

    int result = solution(n);

    cout << result << endl;

    return 0;
}


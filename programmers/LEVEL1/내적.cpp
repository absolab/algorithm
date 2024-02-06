#include <iostream>
using namespace std;

int solution(int a[], size_t a_len, int b[], size_t b_len) {

    int answer = 0;

    for (int i=0; i<a_len; ++i) {
        answer += a[i] * b[i];
    }

    return answer;
}

int main(void) {

    int a[] = {1, 2, 3, 4};
    int b[] = {-3, -1, 0, 2};

    cout << solution(a, 4, b, 4) << endl;

    return 0;
}
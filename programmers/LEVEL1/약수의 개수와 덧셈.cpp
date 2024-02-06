#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[1001];

int solution(int left, int right) {

    int answer = 0;

    for (int i=1; i<=1000; ++i) {

        for (int j=i; j<=1000; ++j) {

            if (j % i == 0) {
                ++dp[j];
            }
        }
    }

    for (int i = left; i<=right; ++i) {
        if (dp[i] % 2 == 0) {
            answer += i;
        } else {
            answer -= i;
        }
    }

    return answer;
}

int main(void) {

    int left = 13;
    int right = 17;

    int result = solution(left, right);

    cout << result << endl;

    return 0;
}
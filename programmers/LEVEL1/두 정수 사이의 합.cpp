#include <string>
#include <vector>

#include <iostream>
using namespace std;

long long solution(int a, int b) {

    long long answer = 0;

    if (a < b) {

        for (int i=a; i<=b; ++i) {
            answer += i;
        }

    } else {

        for (int i=b; i<=a; ++i) {
            answer += i;
        }

    }

    return answer;
}

int main(void) {

    int a = 3;
    int b = 5;

    long long result = solution(a, b);

    cout << result << endl;

    return 0;
}
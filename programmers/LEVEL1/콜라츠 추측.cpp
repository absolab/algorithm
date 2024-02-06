#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {

    long long n = num;
    int answer = 0;

    for (int i=0; i<500; ++i) {

        if (n == 1) {
            answer = i;
            break;
        }

        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }

    if (n != 1) {
        answer = -1; 
    }

    return answer;
}

int main(void) {

    int num = 6;
    int result = solution(num);

    cout << result << endl;

    return 0;
}
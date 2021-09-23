#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


long long solution(long long n) {

    long long answer = 0;

    long long temp = sqrt(n);
    if (temp*temp == n) {
        answer = (temp+1)*(temp+1);
    } else {
        answer = -1;
    }

    return answer;
}


int main(void) {

    long long n = 121;

    long long result = solution(n);

    cout << result << endl;

    return 0;
}
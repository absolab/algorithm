#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {

    bool answer = true;
    int x2 = x;
    int sum = 0;
    int i = 0;
    do {
        i = x % 10;
        x /= 10;
        sum += i;
    } while (x != 0);


    if (x2 % sum == 0) {
        answer = true;
    } else {
        answer = false;
    }

    return answer;
}

int main(void) {

    int x = 10;

    bool result = solution(x);

    cout << result << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int n, int a, int b) {

    int answer = 0;

    while (1) {
        ++answer;
        ++a;
        ++b;

        if (a/2 == b/2) { break; }

        a /= 2;
        b /= 2;
    }

    return answer;
}

int main(void) {

    int n = 8;
    int a = 4;
    int b = 7;

    int result = solution(n, a, b);
    
    cout << result << endl;

    return 0;
}
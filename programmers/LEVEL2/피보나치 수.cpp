#include <vector>
#include <string>
#include <iostream>

using namespace std;

int Fibonacchis[100001];

int solution(int n) {

    int answer = 0;

    Fibonacchis[0] = 0;
    Fibonacchis[1] = 1;

    for (int i=2; i<=n; ++i) {
        Fibonacchis[i] = (Fibonacchis[i-1] % 1234567 + Fibonacchis[i-2] % 1234567) % 1234567;
    }

    answer = Fibonacchis[n];

    return answer;
}

int main(void) {

    int n = 3;

    int result = solution(n);

    cout << result << endl;

    return 0;
}
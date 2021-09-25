#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) {

    vector<int> answer;

    int gcd = 0;
    int lcm = 0;

    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }

    for (int i=1; i<=n; ++i) {
        if (n % i == 0 && m % i == 0) {
            gcd = i;
        }
    }

    lcm = n * m / gcd;

    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}

int main(void) {

    int n = 3;
    int m = 12;

    vector<int> result = solution(n, m);

    for (int i=0; i<result.size(); ++i) {

        cout << result[i] << endl;
    }

    return 0;
}
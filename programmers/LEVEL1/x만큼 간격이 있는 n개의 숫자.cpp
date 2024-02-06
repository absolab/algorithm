#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(int x, int n) {

    vector<long long> answer;
    long long x2 = x;
    for (int i=0; i<n; ++i) {
        answer.push_back(x2);
        x2 += x;
    }

    return answer;
}

int main(void) {

    int x = 2;
    int n = 5;

    vector<long long> result = solution(x, n);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
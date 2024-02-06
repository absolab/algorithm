#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(long long n) {

    vector<int> answer;

    do {
        answer.push_back(n%10);
        n /= 10;
    } while (n != 0);

    return answer;
}

int main(void) {

    long long n = 12345;

    vector<int> result = solution(n);

    for (int i=0; i<result.size(); ++i) {

        cout << result[i] << endl;
    }

    return 0;
}
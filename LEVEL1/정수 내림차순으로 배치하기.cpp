#include <string>
#include <vector>
#include <iostream>

#include <algorithm>
using namespace std;

long long solution(long long n) {

    long long answer = 0;

    vector<int> n2arr;

    do {
        n2arr.push_back(n % 10);
        n /= 10;
    } while (n != 0);

    sort(n2arr.begin(), n2arr.end());

    int count = n2arr.size();

    for (int i=1; i<=count; ++i) {

        answer *= 10;
        answer += n2arr[count-i];
    }


    return answer;
}

int main(void) {

    long long n = 118372;

    long long result = solution(n);

    cout << result << endl;

    return 0;
}
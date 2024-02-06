#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int n) {

    int answer = 0;

    for (int i=1; i<n; ++i) {
        int temp = 0;

        for (int j=i; j<n; ++j) {
            temp += j;

            if (temp == n) {
                ++answer;
                break;
            }else if (temp > n) break;
        }
    }

    ++answer;

    return answer;
}

int main(void) {

    int n = 10000;
    int result = solution(n);
    cout << result << endl;

    return 0;
}
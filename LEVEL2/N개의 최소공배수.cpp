#include <vector>
#include <string>
#include <iostream>

using namespace std;

int GCD(int a, int b) {
    if (a < b) { swap(a,b); }

    int r = a % b;

    if (r == 0) return b;
    return GCD(b, r);
}

int solution(vector<int> arr) {

    int answer = arr[0];
    int next;

    for (int i=1; i<arr.size(); ++i) {
        next = arr[i];
        answer *= next / GCD(answer, next);
    }

    return answer;
}

int main(void) {

    vector<int> arr = {2, 6, 8, 14};
    int result = solution(arr);
    cout << result << endl;

    return 0;
}
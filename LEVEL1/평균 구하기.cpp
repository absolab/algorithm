#include <string>
#include <vector>

#include <iostream>
using namespace std;

double solution(vector<int> arr) {

    double answer = 0;

    int count = arr.size();

    for (int i=0; i<arr.size(); ++i) {
        answer += arr[i];
    }
    answer /= count;

    return answer;
}

int main(void) {

    vector<int> arr = {1, 2, 3, 4};

    double result = solution(arr);

    cout << result << endl;

    return 0;
}
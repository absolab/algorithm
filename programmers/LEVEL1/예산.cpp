#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {

    int answer = 0;

    sort(d.begin(), d.end());

    int sum = 0;
    for (int i=0; i<d.size(); ++i) {

        ++answer;
        sum += d[i];

        if (budget < sum) {
            --answer;
            break;
        }
    }

    return answer;
}

int main(void) {

    vector<int> d = {1, 3, 2, 5, 4};
    int budget = 9;

    int result = solution(d, budget);

    cout << result << endl;

    return 0;
}
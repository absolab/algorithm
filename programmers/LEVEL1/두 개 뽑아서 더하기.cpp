#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[201];

vector<int> solution(vector<int> numbers) {

    vector<int> answer;

    for (int i=0; i<numbers.size(); ++i)  {
        for (int j=i; j<numbers.size(); ++j) {
            if (i != j) {
                ++dp[numbers[i] + numbers[j]];
            }
        }
    }

    for (int i=0; i<201; ++i) {
        if(dp[i] != 0) answer.push_back(i);
    }

    return answer;
}

int main(void) {

    vector<int> numbers = {2, 1, 3, 4, 1};

    vector<int> result = solution(numbers);

    for (int i=0; i<result.size(); ++i) {

        cout << result[i] << " ";
    }
}
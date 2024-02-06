#include <vector>
#include <iostream>

using namespace std;

int dp[200001];

int solution(vector<int> nums) {

    int answer = 0;
    int type = 0;
    
    for (int i=0; i<nums.size(); ++i) {

        ++dp[nums[i]];
    }

    for (int i=1; i<=200000; ++i) {
        if (dp[i] != 0) ++type;
    }

    answer = nums.size() / 2;

    if (answer > type) answer = type;

    return answer;
}

int main(void) {

    vector<int> nums = {3, 1, 2, 3};

    int result = solution(nums);

    cout << result << endl;

    return 0;
}
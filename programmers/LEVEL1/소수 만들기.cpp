#include <iostream>
using namespace std;

int a[70000];

int solution(int nums[], size_t nums_len) {

    int answer = 0;

    // 소수 구하기
    for (int i=2; i<50000; ++i) {
        int j = i + i;
        while (j < 50000) {
            a[j] = 1;
            j += i;
        }
    }

    // 3개 합
    for (int i=0; i<nums_len; ++i) {
        for (int j=i+1; j<nums_len; ++j) {
            for (int k=j+1; k<nums_len; ++k) {
                if (a[nums[i]+nums[j]+nums[k]] == 0) answer++;
            }
        }
    }
    
    return answer;
}

int main(void) {

    int nums[] = {1, 2, 3, 4};
    cout << solution(nums, 4) << endl;
}


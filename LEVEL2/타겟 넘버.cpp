#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> v;
int answer;

void dfs(vector<int> numbers, int target) {
    if (v.size() == numbers.size()) {
        // 동작 구현

        int sum = 0;
        for (int i=0; i<numbers.size(); ++i) {
            if (v[i] == 0) {
                sum += numbers[i];
            } else {
                sum -= numbers[i];
            }
        }

        if (sum == target) ++answer;

        return;
    }

    v.push_back(1);
    dfs(numbers, target);
    v.pop_back();
    v.push_back(0);
    dfs(numbers, target);
    v.pop_back();
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, target);

    return answer;
}

int main(void) {

    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;

    int result = solution(numbers, target);
    
    cout << result << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int arr[100001];

vector<int> solution(vector<int> prices) {

    vector<int> answer;

    vector<int> v;
    vector<int> times;
    
    v.push_back(prices[0]);
    times.push_back(0);

    int i=1;
    while (i < prices.size() - 1) {

        // 가격이 떨어졌는지 확인
        if (v.back() <= prices[i]) {
            v.push_back(prices[i]);
            times.push_back(i);
            i++;

        // 떨어짐
        } else {
            arr[times.back()] = i - times.back();
            v.pop_back();
            times.pop_back();
        }
    }

    int k=0;
    for (int j=0; j<prices.size()-1; ++j) {

        // 0: 끝까지 떨어지지 않음
        if (arr[j] == 0) {
            // 전체에서 k초만큼 빼준다
            answer.push_back(i - times[k++]);

        } else {    
            answer.push_back(arr[j]);
        }
    }
    answer.push_back(0);
    return answer;
}

int main(void) {

    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> result = solution(prices);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

// 비교 함수
bool compare(pair<int,int> i, pair<int,int> j) {
    return i.second > j.second;
}

string solution(vector<int> numbers) {

    string answer = "";

    vector<pair<int,int>> my_numbers;       // <값, 가중치>

    for (int i=0; i<numbers.size(); ++i) {

        const int num = numbers[i];
        int weight = num;
        
        // 가중치 계산

        // num 이 한 자릿수면 (num = 2 -> 2222)
        if (num < 10) {
            while (weight < 1000 && weight != 0) {
                weight = weight * 10 + num;
            }

        // (21 -> 2121)
        } else if (num < 100) {
            weight = weight * 100 + weight;
        
        // (213 -> 2132)
        } else if (num < 1000) {
            weight = weight * 10 + weight / 100;
        }

        my_numbers.push_back(make_pair(num, weight));
    }

    // 가중치를 기준으로 정렬
    sort(my_numbers.begin(), my_numbers.end(), compare);

    if (my_numbers[0].first == 0) {
        answer = "0";
    } else {
        for (int i=0; i<my_numbers.size(); ++i) {
            answer += to_string(my_numbers[i].first);
        }
    }
    return answer;
}

int main(void) {

    vector<int> numbers = {12, 1213};
    string result = solution(numbers);

    cout << result << endl;

    return 0;
}
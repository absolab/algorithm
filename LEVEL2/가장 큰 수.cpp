#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

bool compare(pair<int,int> i, pair<int,int> j) {
    return i.second > j.second;
}

string solution(vector<int> numbers) {

    string answer = "";

    vector<pair<int,int>> my_numbers;
    for (int i=0; i<numbers.size(); ++i) {
        int num = numbers[i];
        int num2 = num;
        
        if (num < 10) {
            while (num2 < 1000 && num2 != 0) {
                num2 = num2 * 10 + num;
            }
        } else if (num < 100) {
            num2 = num2 * 100 + num2;
        } else if (num < 1000) {
            num2 = num2 * 10 + num2 / 100;
        }

        my_numbers.push_back(make_pair(num, num2));
    }

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
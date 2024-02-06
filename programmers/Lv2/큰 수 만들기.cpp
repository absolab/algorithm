#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(string number, int k) {

    string answer = "";

    vector<int> v;

    // 입력받은 숫자를 각 각 벡터에 담는다
    for (int i=0; i<number.size(); ++i) {
        v.push_back(number[i] - '0');
    }

    vector<int> v2;
    int erase_count = 0;
    int idx = 0;
    while (erase_count != k) {
        // 맨 처음
        if (v2.size() == 0) {
            v2.push_back(v[idx++]);
            continue;
        }

        // 뒤에 더 큰 숫자가 있으면 앞에 숫자를 지운다
        if (v2.back() < v[idx]) {
            v2.pop_back();
            erase_count++;
        } else {
            v2.push_back(v[idx++]);
        }
    }

    for (int i=0; i<v2.size(); ++i) {
        answer += to_string(v2[i]);
    }

    for (int i=idx; i<v.size(); ++i) {
        answer += to_string(v[i]);
    }

    return answer;
}

int main(void) {

    string number = "1924";
    int k = 2;

    string result = solution(number, k);
    cout << result << endl;

    return 0;
}
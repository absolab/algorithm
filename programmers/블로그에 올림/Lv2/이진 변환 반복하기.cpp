#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(string s) {

    vector<int> answer;

    int zero_count = 0;         // 지운 0의 개수
    int change_count = 0;       // 변환 횟수

    do {
        // 0 지우기
        string temp = "";
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '1') {
                temp += '1';
            } else {
                zero_count++;
            }
        }
        s = temp;

        // 길이를 2진수로 변환
        temp = "";
        int num = s.size();
        while (num != 0) {
            if (num % 2 == 1) {
                temp += '1';
            } else {
                temp += '0';
            }
            num /= 2;
        }

        // 뒤집기 (2진수 변환의 연장)
        s = "";
        for (int i=0; i<temp.size(); ++i) {
            s += temp[temp.size() - i - 1];
        }
        change_count++;

    } while (s != "1");

    answer.push_back(change_count);
    answer.push_back(zero_count);

    return answer;
}

int main(void) {

    string s = "110010101001";
    vector<int> result = solution(s);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
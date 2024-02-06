#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {

    map<string, string> names;      // <유저아이디, 닉네임>
    vector<string> answer;

    // 문자열 분리
    vector<vector<string>> my_record;   // 분리한 문자열을 저장할 공간

    for (int i=0; i<record.size(); ++i) {
        vector<string> div;
        int start_pos = 0;

        for (int j=0; j <= record[i].size(); ++j) {

            char c = record[i][j];

            if (c == ' ' || j == record[i].size()) {
                div.push_back(record[i].substr(start_pos, j-start_pos));
                start_pos = j + 1;
            }
        }

        my_record.push_back(div);
    }

    // 사람들의 아이디와 최종 닉네임 저장
    for (int i=0; i<my_record.size(); ++i) {

        if (my_record[i][0] == "Enter" || my_record[i][0] == "Change") {
            // 키와 값 추가 or 이미 키 값이 있으면 업데이트
            if ((names.insert(make_pair(my_record[i][1], my_record[i][2]))).second == false) {
                names[my_record[i][1]] = my_record[i][2];
            }
        }
    }

    // Enter, Leave에 따른 문자열 출력
    for (int i=0; i<my_record.size(); ++i) {

        string str;

        if (my_record[i][0] == "Enter") {
            str = names[my_record[i][1]];
            str += "님이 들어왔습니다.";
            answer.push_back(str);
        } else if (my_record[i][0] == "Leave") {
            str = names[my_record[i][1]];
            str += "님이 나갔습니다.";
            answer.push_back(str);
        }
    }

    return answer;
}

int main(void) {

    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};

    vector<string> result = solution(record);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}
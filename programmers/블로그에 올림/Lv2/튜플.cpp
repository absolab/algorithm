#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

bool visit[100001];

// sort의 비교 함수
bool compare(vector<int> i, vector<int> j) {
    return i.size() < j.size();
}

vector<int> solution(string s) {

    vector<int> answer;

    // 1차 분리 (중괄호, 중괄호 사이 콤마 제거)
    vector<string> sep;
    int sep_pos = 2;
    for (int i=3; i<s.size()-1; ++i) {
        char c = s[i];
        if (c == '}') {
            sep.push_back(s.substr(sep_pos, i - sep_pos));
            sep_pos = i + 3;
            i += 3;     // '},{' 3개를 뛰어넘음
        }
    }

    // 정수형 배열로 변경
    vector<vector<int>> v;
    for (int i=0; i<sep.size(); ++i) {
        string temp_str = sep[i];
        int pre_c_pos = 0;
        v.push_back(vector<int>());
        for (int j=1; j<temp_str.size(); ++j) {
            char c = temp_str[j];
            if (c < '0' || c > '9') {
                v[i].push_back(stoi(temp_str.substr(pre_c_pos, j-pre_c_pos)));
                pre_c_pos = j+1;
            }
        } v[i].push_back(stoi(temp_str.substr(pre_c_pos, temp_str.size() - pre_c_pos)));
    }

    // 원소의 개수 순으로 정렬
    sort(v.begin(), v.end(), compare);

    // 처음 나온 숫자 추가
    for (int i=0; i<v.size(); ++i) {

        for (int j=0; j<v[i].size(); ++j) {

            if (visit[v[i][j]] == false) {
                visit[v[i][j]] = true;
                answer.push_back(v[i][j]);
                break;
            }
        }
    }

    return answer;
}

int main(void) {

    string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";    
    vector<int> result = solution(s);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
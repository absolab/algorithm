#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {

    int answer = 0;

    bool is_visited[8] = {0, };
    vector<char> line = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    do {
        bool is_satisfied = true;

        for (int i=0; i<n; ++i) {
            
            char friend1 = data[i][0];
            char friend2 = data[i][2];
            int friend1_pos, friend2_pos;

            // 위치 확인
            for (int j=0; j<8; ++j) {
                if (line[j] == friend1) friend1_pos = j;
                if (line[j] == friend2) friend2_pos = j;
            }

            // 조건 계산
            int gap = abs(friend1_pos - friend2_pos);   // 현재 간격
            int want_gap = data[i][4] - '0' + 1;        // 원하는 간격
            char c = data[i][3];

            // 조건 확인
            if (c == '=' && gap != want_gap) {
                is_satisfied = false;
            } else if (c == '>' && gap <= want_gap) {
                is_satisfied = false;
            } else if (c == '<' && gap >= want_gap) {
                is_satisfied = false;
            }
        }

        if (is_satisfied) { ++answer; }     // 조건을 만족하면 1 추가

    } while(next_permutation(line.begin(), line.end()));

    return answer;
}

int main(void) {

    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};

    int result = solution(n, data);

    cout << result << endl;

    return 0;
}
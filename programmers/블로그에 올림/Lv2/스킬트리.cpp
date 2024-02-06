#include <vector>
#include <string>
#include <iostream>

using namespace std;

int skills[26];

int solution(string skill, vector<string> skill_trees) {

    int answer = 0;

    // 순서가 존재하는 스킬과 해당 순서 표시
    for (int i=0; i<skill.size(); ++i) {
        skills[skill[i] - 'A'] = i+1;
    }

    // 스킬트리 한 개씩 확인
    for (int i=0; i<skill_trees.size(); ++i) {

        string s = skill_trees[i];
        int level = 0;
        bool check = true;

        for (int j=0; j<s.size(); ++j) {
            
            // 배울 수 없는 스킬인지 확인
            if (skills[s[j] - 'A'] - level > 1) {
                check = false;
                break;
            }

            // 순서가 존재하는 스킬의 현재 배운 단계 업데이트
            level = max(level, skills[s[j] - 'A']);
        }
        if (check) {
            answer++;
        }
    }

    return answer;
}

int main(void) {

    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

    int result = solution(skill, skill_trees);
    cout << result << endl;

    return 0;
}
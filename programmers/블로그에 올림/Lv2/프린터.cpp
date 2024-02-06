#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

    int answer = 0;
    int priorities_count[10] = {0, };       // 1~9 중요도 문서의 개수
    int max = -1;

    vector<pair<int,bool>> my_priorities;   // 뽑아야 하는 문서를 표시할 수 있는 컨테이너

    for (int i=0; i<priorities.size(); ++i) {

        // 중요도 최대값 갱신
        if (max < priorities[i]) {
            max = priorities[i];
        }

        // 해당 중요도 문서 개수 추가
        ++priorities_count[priorities[i]];

        // 복사 배열에 값 추가 (뽑아야 하는 문서 표시)
        if (i == location) {
            my_priorities.push_back(make_pair(priorities[i], true));
        } else {
            my_priorities.push_back(make_pair(priorities[i], false));
        }
    }


    for (int i=0; i<my_priorities.size(); ++i) {

        // 최대 중요도 문서를 다 뽑았으면 한단계 밑으로
        if (priorities_count[max] == 0) {
            max--;
            i--;
            continue;
        }

        if (my_priorities[i].first == max) {
            ++answer;
            --priorities_count[max];

            // 뽑아야 하는 문서면 끝
            if (my_priorities[i].second == true) {
                break;
            }

        } else {
            // 계속 뒤에 추가
            my_priorities.push_back(my_priorities[i]);
        }
    }

    return answer;
}

int main(void) {

    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;

    int result = solution(priorities, location);
    
    cout << result << endl;

    return 0;
}
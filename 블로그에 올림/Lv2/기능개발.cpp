#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> answer;
    int pos = 0;
    int date = 1;

    while(pos < progresses.size()) {

        int count = 0;      // 한꺼번에 배포되는 수
        int i=pos;          

        // 시작점 부터 연속으로 진행도가 100 이상을 찾음
        for (; i<progresses.size(); ++i) {

            // 진행도가 100 이상인 경우
            if (progresses[i] + speeds[i] * date >= 100) {

                ++count;

            } else {

                break;
            }
        }

        // 시작점 업데이트
        pos = i;

        // 배포된게 있으면 한꺼번에 배포된 수 추가
        if (count != 0) {

            answer.push_back(count);
        }

        ++date;
    }

    return answer;
}

int main(void) {

    vector<int> progresses = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};

    vector<int> result = solution(progresses, speeds);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {

    int answer = 0;
   
    // 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> little_scoville;
    bool is_greather = false;

    // 큐에 입력값 삽입 (스코빌 지수보다 낮은 것만)
    for (int i=0; i<scoville.size(); ++i) {
        if (scoville[i] < K) {
            little_scoville.push(scoville[i]);
        }
    }

    // 큐가 빌 때 까지 반복
    while(little_scoville.size() != 0) {

        // 한 개 남으면 K를 넘는 음식이 있다고 가정
        // (없다면 is_greather가 false값으로, 아래서 걸러진다.)
        if (little_scoville.size() == 1) {

            ++answer;
            break;
        }

        // 최소값 2개 추출
        int food1 = little_scoville.top();
        little_scoville.pop();

        int food2 = little_scoville.top();
        little_scoville.pop();

        int new_food = food1 + food2 * 2;
        
        // 새로 만든 음식이 충분히 매우면 해당 음식은 버린다.
        if (new_food >= K) {

            is_greather = true;

        // 덜 매우면 다시 큐에 넣는다.
        } else {
            
            little_scoville.push(new_food);
        }

        ++answer;
    }

    // 원하는 맵기에 도달하지 못했을 경우 -1 반환
    if (is_greather == false) { answer = -1; }

    return answer;
}

int main(void) {

    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;

    int result = solution(scoville, K);

    cout << result << endl;

    return 0;
}
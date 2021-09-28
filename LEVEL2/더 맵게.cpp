#include <vector>
#include <string>
#include <iostream>

#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {

    int answer = 0;
   
    priority_queue<int, vector<int>, greater<int>> little_scoville;
    bool is_greather = false;

    for (int i=0; i<scoville.size(); ++i) {
        if (scoville[i] < K) {
            little_scoville.push(scoville[i]);
        }
    }

    while(little_scoville.size() != 0) {

        if (little_scoville.size() == 1) {

            ++answer;
            break;
        }

        int food1 = little_scoville.top();
        little_scoville.pop();

        int food2 = little_scoville.top();
        little_scoville.pop();

        int new_food = food1 + food2 * 2;

        if (new_food >= K) {

            is_greather = true;

        } else {

            little_scoville.push(new_food);
        }

        ++answer;
    }

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
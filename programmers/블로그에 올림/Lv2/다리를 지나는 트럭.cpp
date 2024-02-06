#include <vector>
#include <string>
#include <iostream>

#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int answer = 0;

    int left = 0;
    int total_weight = 0;

    // 다리 위에 있는 트럭과 여태까지 걸린 시간
    queue<pair<int,int>> q;

    do {

        if (q.size() != 0) {
            
            // 다리를 건넌 트럭이 있는지 확인
            if (answer - q.front().second == bridge_length) {
                int temp = q.front().first;
                q.pop();
                total_weight -= temp;
            }
        }

        // 남아있는 트럭이 있으면
        if (left < truck_weights.size()) {
            // 다리가 견딜 수 있는 무게를 초과하지 않으면
            if (total_weight + truck_weights[left] <= weight) {
                total_weight += truck_weights[left];
                q.push(make_pair(truck_weights[left], answer));
                ++left;
            }   
        } 
        
        ++answer;

    } while (q.size() != 0);

    return answer;
}

int main(void) {

    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};
 
    int result = solution(bridge_length, weight, truck_weights);

    cout << result << endl;

    return 0;
}
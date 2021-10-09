#include <vector>
#include <string>
#include <iostream>

#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int answer = 0;

    int left = 0;
    int total_weight = 0;

    queue<pair<int,int>> q;

    do {

        if (q.size() != 0) {
            if (answer - q.front().second == bridge_length) {
                int temp = q.front().first;
                q.pop();
                total_weight -= temp;
            }
        }
        if (left < truck_weights.size()) {
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
#include <vector>
#include <iostream>

#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {

    int answer = 0;

    // 정렬
    sort(people.begin(), people.end());

    int front = 0;
    int back = people.size() - 1;

    // 전체를 순회할 때 까지
    while(front <= back) {
        
        // 양끝 사람 무게의 합
        if (people[front] + people[back] <= limit) {
            front++;
            back--;
            answer++;

        // 초과하면 무거운쪽을 하나 뺀다
        } else {
            answer++;
            back--;
        }
    }

    return answer;
}

int main(void) {

    vector<int> people = {70, 50, 80, 50};
    int limit = 100;

    int result = solution(people, limit);
    cout << result << endl;

    return 0;
}
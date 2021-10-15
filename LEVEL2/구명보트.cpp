#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {

    int answer = 0;

    sort(people.begin(), people.end());

    int front = 0;
    int back = people.size() - 1;

    while(front <= back) {
        if (people[front] + people[back] <= limit) {
            front++;
            back--;
            answer++;
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
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

    int answer = 0;
    int priorities_count[10] = {0, };
    int max = -1;

    vector<pair<int,bool>> my_priorities;
    for (int i=0; i<priorities.size(); ++i) {
        if (max < priorities[i]) {max = priorities[i];}
        ++priorities_count[priorities[i]];

        if (i == location) {
            my_priorities.push_back(make_pair(priorities[i], true));
        } else {
            my_priorities.push_back(make_pair(priorities[i], false));
        }
    }


    for (int i=0; i<my_priorities.size(); ++i) {

        if (priorities_count[max] == 0) {
            max--;
            i--;
            continue;
        }

        if (my_priorities[i].first == max) {
            ++answer;
            --priorities_count[max];
            if (my_priorities[i].second == true) {
                break;
            }
        } else {
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
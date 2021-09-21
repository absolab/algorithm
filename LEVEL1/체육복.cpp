#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    int answer = n;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (vector<int>::iterator lost_iter = lost.begin(); lost_iter != lost.end(); ++lost_iter) {

        for (vector<int>::iterator iter = reserve.begin(); iter != reserve.end(); ++iter) {

            if (*lost_iter == *iter) {
                lost.erase(lost_iter);
                reserve.erase(iter);
                lost_iter--;
                break;
            }
        }
    }

    for (int i=0; i<lost.size(); ++i) {

        bool get = false;

        for (vector<int>::iterator iter = reserve.begin(); iter != reserve.end(); ++iter) {

            int num1 = *iter - 1;
            int num2 = *iter + 1;

            if (lost[i] == num1) {

                reserve.erase(iter);
                get = true;
                break;
            }

            if (lost[i] == num2) {

                reserve.erase(iter);
                get = true;
                break;
            }
        }

        if (get == false) {

            --answer;
        }
    }

    return answer;
}

int main(void) {

    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};

    int answer = solution(n, lost, reserve);

    cout << answer << endl;

    return 0;
}
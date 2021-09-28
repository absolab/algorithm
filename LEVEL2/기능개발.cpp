#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> answer;
    int pos = 0;
    int date = 1;

    while(pos < progresses.size()) {

        int count = 0;
        int i=pos;
        for (; i<progresses.size(); ++i) {

            if (progresses[i] + speeds[i] * date >= 100) {

                ++count;

            } else {

                break;
            }
        }

        pos = i;

        if (count != 0) {

            answer.push_back(count);
        }

        date++;
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
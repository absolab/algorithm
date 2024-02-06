#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {

    vector<int> answer;
    int pre = -1;
    for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter) {

        if (pre == *iter) {
            continue;
        } else {
            answer.push_back(*iter);
        }
        pre = *iter;
    }

    return answer;
}

int main(void) {

    vector<int> arr = {1,1,3,3,0,1,1};

    vector<int> result = solution(arr);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
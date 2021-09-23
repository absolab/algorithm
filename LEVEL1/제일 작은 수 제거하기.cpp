#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {

    vector<int> answer;

    int min = arr[0];
    vector<int>::iterator selected_iter = arr.begin();

    for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter) {
        if (*iter < min) {
            min = *iter;
            selected_iter = iter;
        }
    }

    arr.erase(selected_iter);

    if (arr.size() == 0) {
        answer.push_back(-1);
    } else {
        answer = arr;
    }

    return answer;
}

int main(void) {

    vector<int> n = {4, 3, 2, 1};

    vector<int> result = solution(n);

    for (int i=0; i<result.size(); ++i) {

        cout << result[i] << endl;
    }

    return 0;
}
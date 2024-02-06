#include <string>
#include <vector>

#include <iostream>

using namespace std;

int map[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    vector<string> answer;

    for (int i=0; i<n; ++i) {

        int temp = 1;
        for (int i=0; i<n-1; ++i) temp *= 2;

        for (int j=0; j<n; ++j) {

            map[i][j] += arr1[i] / temp;
            map[i][j] += arr2[i] / temp;

            arr1[i] %= temp;
            arr2[i] %= temp;

            temp = temp / 2;
        }
    }

    for (int i=0; i<n; ++i) {
        string str = "";
        for (int j=0; j<n; ++j) {
            if (map[i][j] != 0) {
                str += '#';
            } else {
                str += ' ';
            }
        }
        answer.push_back(str);
    }

    return answer;
}

int main(void) {

    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};

    vector<string> result = solution(n, arr1, arr2);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
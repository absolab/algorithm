#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    vector<vector<int>> answer;

    int row = arr1.size();
    int col = arr2[0].size();

    for (int x=0; x<row; ++x) {

        vector<int> v;

        for (int y=0; y<col; ++y) {

            int sum = 0;
            for (int i=0; i<arr2.size(); ++i) {
                sum += arr1[x][i] * arr2[i][y];
            }

            v.push_back(sum);
        }

        answer.push_back(v);
    }

    return answer;
}

int main(void) {

    vector<vector<int>> arr1 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> arr2 = {{3, 3}, {3, 3}};

    vector<vector<int>> result = solution(arr1, arr2);
    
    for (int i=0; i<result.size(); ++i) {
        for (int j=0; j<result[i].size(); ++j) {
            cout << result[i][j] << "|";
        }
    } cout << endl;

    return 0;
}
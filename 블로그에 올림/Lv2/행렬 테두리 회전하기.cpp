#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {

    vector<int> answer;
    vector<vector<int>> arr;    // 회전 시킬 배열
    int value = 0;

    // 배열 초기화 
    for (int i=0; i<rows; ++i) {
        arr.push_back(vector<int>());
        for (int j=0; j<columns; ++j) {
            arr[i].push_back(++value);
        }
    }

    for (int i=0; i<queries.size(); ++i) {

        // LT
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        // RB
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        
        int min = 123456;   // 최대 100x100 행렬

        // 회전하기
        // 중간에 움직이는 숫자의 최솟값을 업데이트 한다

        // 윗줄 오른쪽으로 밀기
        int next_value = arr[x1-1][y1-1];
        if (next_value < min) min = next_value;
        int temp;
        for (int j=1; j<=y2-y1; ++j) {
            temp = next_value;
            next_value = arr[x1-1][y1-1+j];
            arr[x1-1][y1-1+j] = temp;
            if (next_value < min) min = next_value;
        }

        // 오른쪽줄 아래로 밀기
        for (int j=1; j<=x2-x1; ++j) {
            temp = next_value;
            next_value = arr[x1-1+j][y2-1];
            arr[x1-1+j][y2-1] = temp;
            if (next_value < min) min = next_value;
        }

        // 아랫줄 왼쪽으로 밀기
        for (int j=1; j<= y2-y1; ++j) {
            temp = next_value;
            next_value = arr[x2-1][y2-1-j];
            arr[x2-1][y2-1-j] = temp;
            if (next_value < min) min = next_value;
        }

        // 왼쪽줄 위로 밀기
        for (int j=1; j<= x2-x1; ++j) {
            temp = next_value;
            next_value = arr[x2-1-j][y1-1];
            arr[x2-1-j][y1-1] = temp;
            if (next_value < min) min = next_value;
        }
        
        answer.push_back(min);
    }

    return answer;
}

int main(void) {

    int rows = 3;
    int columns = 3;
 
    vector<vector<int>> queries ={{1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3}};

    vector<int> result = solution(rows, columns, queries);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
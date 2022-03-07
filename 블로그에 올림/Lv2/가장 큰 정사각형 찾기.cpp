#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board) {

    int answer = 0;

    int row = board.size();
    int col = board[0].size();

    answer = board[0][0];

    for (int i=1; i<row; ++i) {
        for (int j=1; j<col; ++j) {
            if (board[i][j] == 0) continue;

            int n1 = board[i-1][j-1];
            int n2 = board[i][j-1];
            int n3 = board[i-1][j];

            board[i][j] = min(n1, min(n2, n3)) + 1;

            answer = max(answer, board[i][j]);
        }
    }

    return answer*answer;
}

int main(void) {

    vector<vector<int>> board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};;

    int result = solution(board);

    cout << result << endl;

    return 0;
}
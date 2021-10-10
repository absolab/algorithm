#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {

    int answer = 0;

    bool is_deleted = false;
    do {
        is_deleted = false;

        // 사각형 찾기
        vector<pair<int,int>> square;
        for (int i=0; i<m-1; ++i) {
            for (int j=0; j<n-1; ++j) {
                
                char c = board[i][j];
                if (c == '-') continue;

                char c1 = board[i][j+1];
                char c2 = board[i+1][j];
                char c3 = board[i+1][j+1];
                if (c == c1 && c == c2 && c == c3) {
                    square.push_back(make_pair(i, j));
                    square.push_back(make_pair(i+1, j));
                    square.push_back(make_pair(i, j+1));
                    square.push_back(make_pair(i+1, j+1));
                }            
            }
        }
        // 지우기
        for (int i=0; i<square.size(); ++i) {
            board[square[i].first][square[i].second] = '-';
            is_deleted = true;
        }

        // 내리기
        bool is_moved = false;
        do {
            is_moved = false;
            for (int i=1; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (board[i][j] == '-' && board[i-1][j] != '-') {
                        swap(board[i][j], board[i-1][j]);
                        is_moved = true;
                    }
                }
            }
        } while (is_moved);

    } while (is_deleted);
    
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (board[i][j] == '-') {
                answer++;
            }
        }
    }

    return answer;
}

int main(void) {

    int m = 6;
    int n = 6;
    vector<string> board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};

    int result = solution(m, n, board);
    cout << result << endl;

    return 0;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    vector<int> stack;
    int gacha;
    int answer = 0;

    for (vector<int>::iterator iter = moves.begin(); iter != moves.end(); ++iter) {

        int line = *iter-1;

        for (int i=0; i<board.size(); ++i) {
                       
            if (board[i][line] != 0) {

                gacha = board[i][line];
                board[i][line] = 0;
                
                if (stack.size() == 0) {
                    stack.push_back(gacha);
                }
                else if (stack.back() == gacha) {
                    
                    stack.pop_back();
                    ++answer;

                } else {

                    stack.push_back(gacha);
                }

                break;
            }
        }
    }

    return answer * 2; // 한 번 터질 때 2개씩 터져서 2배
}

int main(void) {

    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};

    cout << solution(board, moves) << endl;
}
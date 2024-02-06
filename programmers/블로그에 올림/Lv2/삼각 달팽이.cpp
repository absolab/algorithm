#include <vector>
#include <string>
#include <iostream>

using namespace std;

// n은 1 이상 1000 이하
int arr[1001][1001];

vector<int> solution(int n) {

    vector<int> answer;

    // 총 숫자의 개수는 1부터 n까지의 합
    int cnt = n * (n + 1) / 2;

    int x = 0, y = 0;   // 좌표
    int dr = 0;         // 방향

    for (int i=1; i<=cnt; ++i) {

        // 아래 방향
        if (dr == 0) {
            arr[x++][y] = i;
            if (x == n || arr[x][y] != 0) {
                x--; y++;
                dr = 1;
            }

        // 오른쪽 방향
        } else if (dr == 1) {
            arr[x][y++] = i;
            if (y == n || arr[x][y] != 0) {
                x--; y-=2;
                dr = 2;
            }
            
        // 위 방향 (대각선)
        } else {
            arr[x--][y--] = i;
            if (arr[x][y] != 0) {
                x+=2; y++;
                dr = 0;
            }
        }
    }

    // 일차원 배열로 변경
    for (int i=0; i<1000; ++i) {
        for (int j=0; j<1000; ++j) {
            if (arr[i][j] == 0) break;
            answer.push_back(arr[i][j]);
        }
    }

    return answer;
}

int main(void) {

    int n = 6;
    vector<int> result = solution(n);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int arr[1000][1000];

vector<int> solution(int n) {

    vector<int> answer;

    int cnt = 1;
    for (int i=2; i<=n; ++i) {
        cnt += i;
    }

    int x = 0;
    int y = 0; 
    int dr = 0;

    for (int i=1; i<=cnt; ++i) {
        if (dr == 0) {
            arr[x++][y] = i;
            if (x == n || arr[x][y] != 0) {
                x--; y++;
                dr = 1;
            }
        } else if (dr == 1) {
            arr[x][y++] = i;
            if (y == n || arr[x][y] != 0) {
                x--; y-=2;
                dr = 2;
            }
            
        } else {
            arr[x--][y--] = i;
            if (arr[x][y] != 0) {
                x+=2; y++;
                dr = 0;
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << arr[i][j] << "|";
        } cout << endl;
    }

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
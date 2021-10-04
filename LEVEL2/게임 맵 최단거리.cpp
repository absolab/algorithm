#include <vector>
#include <string>
#include <iostream>

#include <queue>
using namespace std;

vector<vector<int>> my_maps;
bool check[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int min_path = 9999999;

class my_class {
public:
    int x, y;
    int depth = 1;

    my_class(int x, int y, int depth) {
        this->x = x;
        this->y = y;
        this->depth = depth;
    }
};

queue<my_class> q;

void bfs() {

    q.push(my_class(0,0,1));

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int depth = q.front().depth;
        q.pop();

        if (x == my_maps.size()-1 && y == my_maps[0].size()-1) {
            min_path = (min_path < depth) ? min_path : depth;
            return;
        }

        for (int i=0; i<4; ++i) {

            // out of range
            if (x + dx[i] < 0 || x + dx[i] >= my_maps.size()) continue;
            if (y + dy[i] < 0 || y + dy[i] >= my_maps[0].size()) continue;
            // is wall?
            if (my_maps[x+dx[i]][y+dy[i]] == 0) continue;

            if (check[x+dx[i]][y+dy[i]] == true) continue;

            check[x+dx[i]][y+dy[i]] = true;
            q.push(my_class(x+dx[i], y+dy[i], depth + 1));
        }
    }
}

int solution(vector<vector<int>> maps) {

    int answer = 0;
    my_maps = maps;

    bfs();

    answer = (min_path != 9999999) ? min_path : -1;

    return answer;
}

int main(void) {

    vector<vector<int>> maps = {{1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1}};
    int result = solution(maps);
    
    cout << result << endl;

    return 0;
}
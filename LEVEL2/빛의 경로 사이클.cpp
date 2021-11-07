#include <vector>
#include <string>
#include <iostream>

#include <map>
#include <algorithm>
using namespace std;

vector<string> mygrid;
map<pair<int,int>, bool> path;
vector<int> answer;

int max_x;
int max_y;

void simulation(int x, int y, int direction, int length) {

    // direction: 이전에 향한 방향
    // [0: →] [1: ↓] [2: ←] [3: ↑]

    char c = mygrid[x][y];

    int next_direction = -1;
    int next_x, next_y;
    bool is_outside = false;

    if (c == 'S') {
        next_direction = direction;
    } else if (c == 'L') {
        next_direction = (direction + 3) % 4;
    } else { // if (c == 'R') {
        next_direction = (direction + 1) % 4;
    }


    if (next_direction == 0) {
        if (x + 1 == max_x) {is_outside = true;}
        next_x = (x + 1) % max_x;
        next_y = y;
    } else if (next_direction == 1) {
        if (y + 1 == max_y) {is_outside = true;}
        next_x = x;
        next_y = (y + 1) % max_y;
    } else if (next_direction == 2) {
        if (x - 1 == -1) {is_outside = true;}
        next_x = (x - 1 + max_x) % max_x;
        next_y = y;
    } else { // if (next_direction == 3) {
        if (y - 1 == - 1) {is_outside = true;}
        next_x = x;
        next_y = (y -1 + max_y) % max_y;
    }
    
    int p1 = x*1024 + y;
    int p2 = next_x*1024 + next_y;
    if (is_outside) p2 += 10000000*(direction+1);

    if (path.find(make_pair(p1, p2)) == path.end()) {
        path.insert(make_pair(make_pair(p1,p2), true));
        simulation(next_x, next_y, next_direction, length+1);
    } else {
        if (length != 0) {
            answer.push_back(length);
        }
    }
}

vector<int> solution(vector<string> grid) {

    mygrid = grid;

    max_x = grid.size();
    max_y = grid[0].size();

    for (int x=0; x<max_x; ++x) {

        for (int y=0; y<max_y; ++y) {

            for (int d=0; d<4; ++d) {
                
                simulation(x, y, d, 0);
            }

        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main(void) {

    vector<string> grid = {"SL","LR"};
    vector<int> result = solution(grid);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
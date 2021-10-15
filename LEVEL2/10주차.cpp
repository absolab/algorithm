#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

vector<vector<int>> _line;
int max_size;
vector<long long> v;

map<pair<long long,long long>,bool> points;
long long max_x = LONG_LONG_MIN;
long long max_y = LONG_LONG_MIN;
long long min_x = LONG_LONG_MAX;
long long min_y = LONG_LONG_MAX;

void dfs() {
    if (v.size() == 2) {

        // 교점 구하기
        vector<int> fx1 = _line[v[0]];
        vector<int> fx2 = _line[v[1]];

        long long A = fx1[0];
        long long B = fx1[1];
        long long E = fx1[2];

        long long C = fx2[0];
        long long D = fx2[1];
        long long F = fx2[2];

        if (A*D == B*C) return;

        long long x, y, x_up, y_up, down;

        x_up = B*F - E*D;
        y_up = E*C - A*F;
        down = A*D - B*C;

        if (x_up % down != 0) return;
        if (y_up % down != 0) return;

        x = x_up / down;
        y = y_up / down;
                
        if (max_x < x) max_x = x;
        if (max_y < y) max_y = y;
        if (min_x > x) min_x = x;
        if (min_y > y) min_y = y;

        points.insert(make_pair(make_pair(x, y), true));

        return;
    }

    int start = (v.size() == 0) ? 0 : v[0]+1;
    for (int i=start; i<max_size; ++i) {
        v.push_back(i);
        dfs();
        v.pop_back();
    }
}

vector<string> solution(vector<vector<int>> line) {

    vector<string> answer;

    _line = line;
    max_size = line.size();

    dfs();

    for (long long y = max_y; y >= min_y; --y) {
        string s = "";
        for (long long x = min_x; x <= max_x; ++x) {
            if (points.find(make_pair(x,y)) != points.end()) {
                s += '*';
            } else {
                s += '.';
            }
        }
        answer.push_back(s);
    } 

    return answer;
}

int main(void) {

    vector<vector<int>> line = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
    //vector<vector<int>> line = {{0,1,-1},{1,0,-1},{1,0,1}};
    vector<string> result = solution(line);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "\n";
    } cout << endl;

    return 0;
}
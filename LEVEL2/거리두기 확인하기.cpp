#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool is_distanced;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool check[5][5];
vector<char> v;

void dfs(vector<string> place, int x, int y) {

    if (is_distanced == false) return;

    if (v.size() == 3) {
        if (v[0] == 'P' && v[1] == 'O' && v[2] == 'P') { is_distanced = false; }
        else if (v[0] == 'P' && v[1] == 'P') { is_distanced = false; }
        else if (v[1] == 'P' && v[2] == 'P') { is_distanced = false; }
        return;
    }

    for (int i=0; i<4; ++i) {
        if ((x+dx[i]) < 0 || (x+dx[i]) >= 5) continue;
        if ((y+dy[i]) < 0 || (y+dy[i]) >= 5) continue;
        if (check[x+dx[i]][y+dy[i]] == true) continue;

        check[x+dx[i]][y+dy[i]] = true;
        v.push_back(place[x+dx[i]][y+dy[i]]);

        dfs(place, x + dx[i], y + dy[i]);

        check[x+dx[i]][y+dy[i]] = false;
        v.pop_back();
    }
}

void check_place(vector<string> place) {

    for (int i=0; i<5; ++i) {
        for (int j=0; j<5; ++j) {
            dfs(place, i, j);
        }
    }
}

vector<int> solution(vector<vector<string>> places) {

    vector<int> answer;

    for (int i=0; i<places.size(); ++i) {

        is_distanced = true;
        check_place(places[i]);
        if (is_distanced) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        } 
    }    

    return answer;
}

int main(void) {

    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                     {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                     {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                     {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                     {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    vector<int> result = solution(places);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
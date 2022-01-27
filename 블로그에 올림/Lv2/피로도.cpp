#include <string>
#include <vector>

using namespace std;

int max_size;
vector<int> v;
bool visited[8];
int myk;
int max_answer;
vector<vector<int>> mydungeons;

void check() {

    int count = 0;      // 탐험한 던전 수
    int copy_k = myk;   // 남은 피로도

    for (int i=0; i<v.size(); ++i) {
        if (copy_k >= mydungeons[v[i]][0]) {
            copy_k -= mydungeons[v[i]][1];
            ++count;
        }
    }

    max_answer = max(max_answer, count);
}

void dfs() {

    if (v.size() == max_size) {
        check();
        return;
    }

    for (int i=0; i<max_size; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(i);
            dfs();
            v.pop_back();
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {

    int answer = -1;

    max_size = dungeons.size();
    myk = k;
    mydungeons = dungeons;

    dfs();
    answer = max_answer;
    return answer;
}

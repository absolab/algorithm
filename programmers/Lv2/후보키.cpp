#include <vector>
#include <string>
#include <iostream>

#include <map>
using namespace std;

int answer = 0;
vector<vector<string>> _relation;

int max_columns;
int depth;

vector<int> v;
bool visited[8];
int value[] = {1, 2, 4, 8, 16, 32, 64, 128};
vector<int> candidate_key;

void dfs() {
    
    if (v.size() == depth) {
        
        // 선택한 column을 표시
        bool is_candidate_key = true;
        int key = 0;
        for (int i=0; i<v.size(); ++i) {
            key += value[v[i]];
        }

        // 최소성: 키 안에 후보키를 갖고 있으면 후보키가 될 수 없음
        bool is_already_candidate_key = false;
        for (int i=0; i<candidate_key.size(); ++i) {
            if ((key & candidate_key[i]) == candidate_key[i]) {
                is_already_candidate_key = true;
            }
        }
        if (is_already_candidate_key == true) return;

        // 유일성: 중복 되는 값이 없어야 함
        map<string,int> check_dup;
        for (int i=0; i<_relation.size(); ++i) {
            string my_tuple = "";
            for (int j=0; j<v.size(); ++j) {
                my_tuple += _relation[i][v[j]];
                my_tuple += "|";
            }

            if (check_dup.find(my_tuple) == check_dup.end()) {
                check_dup.insert(make_pair(my_tuple, true));
            } else {
                is_candidate_key = false;
                break;
            }
        }

        // 모든 조건을 만족하면 후보키 목록에 추가
        if (is_candidate_key == true) {
            answer++;
            candidate_key.push_back(key);
        }

        return;
    }

    for (int i=(v.size()!= 0)?v.back():0; i<max_columns; ++i) {
        if (visited[i] == true) continue;
        visited[i] = true;
        v.push_back(i);
        dfs();
        v.pop_back();
        visited[i] = false;
    }
}

int solution(vector<vector<string>> relation) {

    _relation = relation;
    max_columns = relation[0].size();

    // 칼럼의 개수
    while(depth <= max_columns) {
        dfs();
        ++depth;
    }

    return answer;
}

int main(void) {

    vector<vector<string>> relation = { {"a","1","aaa","c","ng"},
                                        {"a","1","bbb","e","g"},
                                        {"c","1","aaa","d","ng"},
                                        {"d","2","bbb","d","ng"} };
    int result = solution(relation);

    cout << result << endl;

    return 0;
}
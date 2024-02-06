#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    int number_of_area = 0;         // 영역의 개수
    int max_size_of_area = 0;       // 가장 큰 영역의 크기

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    bool is_colored[100][100] = {false, };  // 방문 했었는지 확인

    for (int i=0; i<m; ++i) {

        for (int j=0; j<n; ++j) {

            int size_of_area = 0;
            const int current_color = picture[i][j];

            if (is_colored[i][j]) { continue; }     // 이미 방문 했으면 패스
            if (picture[i][j] == 0) { continue; }   // 색깔이 없으면 패스

            ++number_of_area;

            // DFS
            vector<pair<int,int>> same_color;       // 같은 영역의 좌표 값 저장
            same_color.push_back(make_pair(i, j));  

            while(same_color.size() > 0) {

                pair<int,int> pre_pos = same_color.back();
                same_color.pop_back();

                int pre_i = pre_pos.first;
                int pre_j = pre_pos.second;

                if (is_colored[pre_i][pre_j]) continue;     // 이미 방문 했으면 패스

                is_colored[pre_i][pre_j] = true;            // 방문 한걸로 변경
                ++size_of_area;

                // 상하좌우 확인
                for (int k=0; k<4; ++k) {

                    int new_i = pre_i+dx[k];
                    int new_j = pre_j+dy[k];

                    if (new_i < 0 || new_i >= m) { continue; }  // 범위를 벗어남
                    if (new_j < 0 || new_j >= n) { continue; }  // 범위를 벗어남
                    if (is_colored[new_i][new_j]) { continue; } // 이미 방문함

                    if (picture[new_i][new_j] == current_color) {
                        same_color.push_back(make_pair(new_i, new_j));
                    }

                }
            }

            // 가장 큰 영역의 크기 저장
            if (max_size_of_area < size_of_area) {
                max_size_of_area = size_of_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_area;
    return answer;
}

int main(void) {

    int m = 6;
    int n = 4;
    vector<vector<int>> picture = {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};

    vector<int> result = solution(m, n, picture);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
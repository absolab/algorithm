#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    bool is_colored[100][100] = {false, };

    for (int i=0; i<m; ++i) {

        for (int j=0; j<n; ++j) {

            int size_of_area = 0;
            vector<pair<int,int>> same_color;
            const int current_color = picture[i][j];

            if (is_colored[i][j]) { continue; }
            if (picture[i][j] == 0) { continue; }

            same_color.push_back(make_pair(i, j));
            ++number_of_area;

            while(same_color.size() > 0) {

                pair<int,int> pre_pos = same_color.back();
                same_color.pop_back();

                int pre_i = pre_pos.first;
                int pre_j = pre_pos.second;

                if (is_colored[pre_i][pre_j]) continue;

                is_colored[pre_i][pre_j] = true;
                ++size_of_area;

                for (int k=0; k<4; ++k) {

                    int new_i = pre_i+dx[k];
                    int new_j = pre_j+dy[k];

                    if (new_i < 0 || new_i >= m) { continue; }
                    if (new_j < 0 || new_j >= n) { continue; }
                    if (is_colored[new_i][new_j]) { continue; }

                    if (picture[new_i][new_j] == current_color) {
                        same_color.push_back(make_pair(new_i, new_j));
                    }

                }
            }
        
            if (max_size_of_one_area < size_of_area) {
                max_size_of_one_area = size_of_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
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
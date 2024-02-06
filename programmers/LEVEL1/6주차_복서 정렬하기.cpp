#include <string>
#include <vector>

#include <iostream>


using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {

    vector<int> answer;

    float win_rate[1000] = {0.0, };
    int heavy_win_count[1000] = {0, };

    for (int i=0; i<weights.size(); ++i) {

        string str = head2head[i];
        int win = 0;
        int total = 0;

        for (int j=0; j<str.length(); ++j) {

            if (str[j] == 'N') {

                // 암것도 안함

            } else if (str[j] == 'W') {

                if (weights[i] < weights[j]) {

                    ++heavy_win_count[i];
                }
                ++win;
                ++total;

            } else { // str[i] == 'L'

                ++total;
            }
        }

        if (total == 0) {

            win_rate[i] = 0;

        } else {

            win_rate[i] = (float)win / (float)total;
        }
    }

    for (int i=0; i<weights.size(); ++i) {
        
        float max = -1;
        int select = -1;

        for (int j=0; j<weights.size(); ++j) {

            if (win_rate[j] > max) {

                max = win_rate[j];
                select = j;

            } else if (win_rate[j] == max) {

                if (heavy_win_count[select] < heavy_win_count[j]) {
                    max = win_rate[j];
                    select = j;
                } else if (heavy_win_count[select] == heavy_win_count[j]) {

                    if (weights[select] < weights[j]) {
                        max = win_rate[j];
                        select = j;
                    }
                }
            }
        }
        
        answer.push_back(select+1);

        win_rate[select] = -1;
    }

    return answer;
}

int main(void) {

    vector<int> weights = {50, 82, 75, 120};
    vector<string> head2head = {"NLWL", "WNLL", "LWNW", "WWLN"};

    vector<int> result = solution(weights, head2head);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
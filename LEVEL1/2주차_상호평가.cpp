#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {

    string answer = "";

    for (int i=0; i<scores.size(); ++i) {

        int score = scores[i][i];
        bool is_min_score = true;
        bool is_max_score = true;

        for (int j=0; j<scores.size(); ++j) {

            if (i == j) continue;

            if (score <= scores[j][i]) {
                is_max_score = false;
            }

            if (score >= scores[j][i]) {
                is_min_score = false;
            }
        }

        if (is_min_score || is_max_score) {
            scores[i][i] = -1;
        }
    }

    for (int i=0; i<scores.size(); ++i) {

        int sum = 0;
        int count = 0;

        for (int j=0; j<scores.size(); ++j) {
            if (scores[j][i] == -1) {
                continue;
            }

            ++count;
            sum += scores[j][i];
        }

        float average = ((float)sum / (float)count);

        if (average < 50) {
            answer += 'F';
        } else if (average < 70) {
            answer += 'D';
        } else if (average < 80) {
            answer += 'C';
        } else if (average < 90) {
            answer += 'B';
        } else {
            answer += 'A';
        }
    }

    return answer;
}

int main(void) {
    
    vector<vector<int>> scores = {{100,90,98,88,65},{50,45,99,85,77},{47,88,95,80,67},{61,57,100,80,65},{24,90,94,75,65}};

    string str = solution(scores);

    cout << str << endl;

    return 0;
}
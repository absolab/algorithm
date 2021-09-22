#include <string>
#include <vector>
#include <iostream>

using namespace std;

int clear[502];
int stop[502];


vector<int> solution(int N, vector<int> stages) {
    
    vector<int> answer;
    vector<pair<int,float>> fail_rate;

    for (int i=0; i < stages.size(); ++i) {

        ++stop[stages[i]];        

        for (int j=1; j<=stages[i]; ++j) {

            ++clear[j];
        }
    }

    for (int i=1; i<=N; ++i) {

        if (clear[i] == 0) {
            fail_rate.push_back(pair<int,float>(i, 0));
        } else {
            fail_rate.push_back(pair<int,float>(i, (float)stop[i] / (float)clear[i]));
        }    
    }

    for (int i=0; i<N; ++i) {

        vector<pair<int,float>>::iterator stage_iter;
        float max = -1;
        
        for (vector<pair<int,float>>::iterator iter = fail_rate.begin(); iter != fail_rate.end(); ++iter) {

            if (max < (*iter).second) {
                stage_iter = iter;
                max = (*iter).second;
            }
        }

        answer.push_back((*stage_iter).first);
        fail_rate.erase(stage_iter);
    }

    return answer;
}

int main(void) {

    int N = 5;
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};

    vector<int> answer = solution(N, stages);

    for (int i=0; i<answer.size(); ++i) {
        cout << answer[i] << " ";
    } cout << endl;
}
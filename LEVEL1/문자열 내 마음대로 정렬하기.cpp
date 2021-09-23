#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<string> solution(vector<string> strings, int n) {

    vector<string> answer;

    int count = strings.size();

    for (int i=0; i<count; ++i) {
        
        unsigned char c = 255;
        vector<string>::iterator selected_iter;

        for (vector<string>::iterator iter = strings.begin(); iter != strings.end(); ++iter) {

            if (c > (*iter)[n]) {

                c = (*iter)[n];
                selected_iter = iter;

            } else if (c == (*iter)[n]) {

                if (*selected_iter > *iter) {

                    c = (*iter)[n];
                    selected_iter = iter;
                }
            }
        }

        answer.push_back(*selected_iter);
        strings.erase(selected_iter);
    }

    return answer;
}

int main(void) {

    vector<string> strings = {"sub", "bed", "car"};
    int n = 1;

    vector<string> result = solution(strings, n);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string>ha[10000]; 

string solution(vector<string> participant, vector<string> completion) {

    string answer = "";

    for (vector<string>::iterator iter = completion.begin(); iter != completion.end(); ++iter) {
        int key = 0;
        for (int i=0; i<(*iter).length(); ++i) {
            key += (*iter)[i];
        }
        key = key * 777 % 10000;

        ha[key].push_back(*iter);
    }

    for (vector<string>::iterator iter = participant.begin(); iter != participant.end(); ++iter) {
        int key = 0;
        string name = *iter;

        for (int i=0; i<(*iter).length(); ++i) {
            key += (*iter)[i];
        }
        key = key * 777 % 10000;

        bool check = false;

        for(vector<string>::iterator iter = ha[key].begin(); iter != ha[key].end(); ++iter) {
            if (name == *iter) {
                ha[key].erase(iter);
                check = true;
                break;
            }
        }

        if (check == false) {
            answer = name;
            break;
        }
    }

    return answer;
}

int main(void) {

    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};

    cout << solution(participant, completion) << endl;
}
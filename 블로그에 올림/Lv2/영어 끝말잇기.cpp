#include <vector>
#include <string>
#include <iostream>

#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {

    vector<int> answer;

    map<string, bool> my_map;
    int user = 0;
    char pre_c = '1';

    for (int i=0; i<words.size(); ++i) {

        if (my_map.find(words[i]) != my_map.end()) {
            // Å»¶ô!
            answer.push_back(user + 1);
            answer.push_back(i/n + 1);
            break;
        }

        if (pre_c != '1' && pre_c != words[i][0]) {
            // Å»¶ô!
            answer.push_back(user + 1);
            answer.push_back(i/n + 1);
            break;
        }

        my_map.insert(make_pair(words[i], true));
        pre_c = words[i][words[i].size()-1];

        user = (user + 1) % n;
    }

    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main(void) {

    int n = 3;
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};

    vector<int> result = solution(n, words);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
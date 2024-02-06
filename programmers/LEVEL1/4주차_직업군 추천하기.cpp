#include <string>
#include <vector>

#include <iostream>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {

    string answer = "";

    string name = "";
    int max = -1;

    for (int i=0; i<table.size(); ++i) {

        int score = 0;

        vector<string> split;

        // 문자열 분리
        string str = table[i];
        int pos1 = 0;
        int pos2 = 0;

        while(1) {

            char c = str[pos2];

            if (c == '\0') {
                split.push_back(str.substr(pos1, pos2-pos1));
                break;
            }

            if (c == ' ') {
                split.push_back(str.substr(pos1, pos2-pos1));
                pos1 = pos2 + 1;
            }

            ++pos2;
        }

        // 점수 계산
        for (int i=1; i<split.size(); ++i) {
            
            for (int j=0; j<languages.size(); ++j) {
                if (split[i] == languages[j]) {
                    score += preference[j] * (split.size() - i);
                }
            }
        }

        if (max < score) {

            name = split[0];
            max = score;

        } else if (max == score) {

            if (name > split[0]) {
                name = split[0];
                max = score;
            }
        }
    }

    answer = name;

    return answer;
}

int main(void) {

    vector<string> table = {"SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"};
    vector<string> languages = {"JAVA", "JAVASCRIPT"};
    vector<int> preference = {7, 5};

    string result = solution(table, languages, preference);

    cout << result << endl;

    return 0;
}
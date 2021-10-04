#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/* cpp:1        java:2      python:4    -:7
 * backend:8    frontend:16             -:24
 * junior:32    senior:64               -:96
 * chiken:128   pizza:256               -:384
*/ 

vector<int> solution(vector<string> info, vector<string> query) {

    vector<int> answer;

    vector<pair<int,int>> my_info;
    vector<pair<int,int>> my_query;

    for (int i=0; i<info.size(); ++i) {
        int idx = 0;
        string str = info[i];

        int num = 0;

        if (str[idx] == 'c') {
            num += 1;
            idx = 4;
        } else if (str[idx] == 'j') {
            num += 2; 
            idx = 5;
        } else {
            num += 4;
            idx = 7;
        }

        if (str[idx] == 'b') {
            num += 8;
            idx += 8;
        } else {
            num += 16;
            idx += 9;
        }

        if (str[idx] == 'j') {
            num += 32;
            idx += 7;
        } else {
            num += 64;
            idx += 7;
        }

        if (str[idx] == 'c') {
            num += 128;
            idx += 8;
        } else {
            num += 256;
            idx += 6;
        }

        int score = stoi(str.substr(idx, str.size() - idx));
        my_info.push_back(make_pair(num, score));
    }

    for (int i=0; i<query.size(); ++i) {
        int idx = 0;
        string str = query[i];

        int num = 0;

        if (str[idx] == 'c') {
            num += 1;
            idx = 8;
        } else if (str[idx] == 'j') {
            num += 2; 
            idx = 9;
        } else if (str[idx] == 'p') {
            num += 4;
            idx = 11;
        } else {
            num += 7;
            idx = 6;
        }

        if (str[idx] == 'b') {
            num += 8;
            idx += 12;
        } else if (str[idx] == 'f') {
            num += 16;
            idx += 13;
        } else {
            num += 24;
            idx += 6;
        }

        if (str[idx] == 'j') {
            num += 32;
            idx += 11;
        } else if (str[idx] == 's'){
            num += 64;
            idx += 11;
        } else {
            num += 96;
            idx += 6;
        }

        if (str[idx] == 'c') {
            num += 128;
            idx += 8;
        } else if (str[idx] == 'p') {
            num += 256;
            idx += 6;
        } else {
            num += 384;
            idx += 2;
        }

        int score = stoi(str.substr(idx, str.size() - idx));

        my_query.push_back(make_pair(num, score));
    }

    for (int i=0; i<my_query.size(); ++i) {

        int satisfied_count = 0;
 
        for (int j=0; j<my_info.size(); ++j) {
            if ((my_query[i].first & my_info[j].first) == my_info[j].first) {
                if (my_query[i].second <= my_info[j].second) {
                    ++satisfied_count;
                }
            }
        }

        answer.push_back(satisfied_count);
    }

    return answer;
}

int main(void) {

    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    
    vector<int> result = solution(info, query);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}

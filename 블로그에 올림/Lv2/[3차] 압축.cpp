#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;


vector<int> solution(string msg) {

    vector<int> answer;
    map<string, int> my_map;

    // 사전에 색인번호 1~26 등록
    char c = 'A';
    for (int i=0; i<26; ++i) {
        string temp = "";
        temp += (c+i);
        my_map.insert(make_pair(temp, i+1));
    }


    int idx = 0;
    while(idx != msg.size()) {
        string w = "";
        char c = '\0';

        w.push_back(msg[idx++]);

        while(1) {

            // 끝에 도달
            if (idx == msg.size()) {
                answer.push_back((*(my_map.find(w))).second);
                break;
            }

            c = msg[idx++];

            // (w+c)가 존재하면 w에 c를 붙이고 넘어감
            if (my_map.find(w+c) != my_map.end()) {

                w.push_back(c);

            // 존재하지 않으면 w+c를 사전에 추가하고 이전 값으로 돌아감
            } else {
                my_map.insert(make_pair(w+c, my_map.size()+1));
                answer.push_back((*(my_map.find(w))).second);
                idx--;
                break;     
            }
        }
        
    }

    return answer;
}

int main(void) {

    string msg = "ABABABABABABABAB";
   
    vector<int> result = solution(msg);
 
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
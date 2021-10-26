#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;


vector<int> solution(string msg) {

    vector<int> answer;
    map<string, int> my_map;

    // 사전 초기화
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

            if (idx == msg.size()) {
                answer.push_back((*(my_map.find(w))).second);
                break;
            }

            c = msg[idx++];

            if (my_map.find(w+c) != my_map.end()) {

                w.push_back(c);

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
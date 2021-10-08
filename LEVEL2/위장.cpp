#include <vector>
#include <string>
#include <iostream>

#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {

    int answer = 1;

    map<string, int> my_map;
    for (int i=0; i<clothes.size(); ++i) {
        map<string,int>::iterator iter = my_map.find(clothes[i][1]);
        if (iter == my_map.end()) {
            my_map.insert(make_pair(clothes[i][1], 1));
        } else {
            (*iter).second++;
        }
    }
    
    for (map<string,int>::iterator iter = my_map.begin(); iter != my_map.end(); ++iter) {
        answer *= (*iter).second + 1;
    }

    --answer;

    return answer;
}

int main(void) {

    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    int result = solution(clothes);
    
    cout << result << endl;

    return 0;
}
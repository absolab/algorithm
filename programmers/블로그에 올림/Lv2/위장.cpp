#include <vector>
#include <string>
#include <iostream>

#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {

    int answer = 1;

    map<string, int> my_map;

    // 맵에 옷들을 추가
    for (int i=0; i<clothes.size(); ++i) {

        // 장착하는 부위 기준으로 검색
        map<string,int>::iterator iter = my_map.find(clothes[i][1]);
        if (iter == my_map.end()) {

            // 기존에 없던 부위면 추가
            my_map.insert(make_pair(clothes[i][1], 1));

        } else {

            // 장착할 아이템의 이름은 필요 없고 개수만 알면 됨
            (*iter).second++;
        }
    }
    
    // 경우의 수 구하기 (장착하지 않는 경우도 있어 +1 해준다.)
    for (map<string,int>::iterator iter = my_map.begin(); iter != my_map.end(); ++iter) {
        answer *= (*iter).second + 1;
    }

    // 아무것도 장착하지 않는 경우
    --answer;

    return answer;
}

int main(void) {

    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    int result = solution(clothes);
    
    cout << result << endl;

    return 0;
}
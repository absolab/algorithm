#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {

    int answer = 0;
    vector<string> v;

    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    // 전부 대문자로 변경
    for (int i=0; i<cities.size(); ++i) {
        string str = cities[i];
        for (int j=0; j<str.size(); ++j) {
            str[j] = toupper(str[j]);
        }
        cities[i] = str;
    }

    for (int i=0; i<cities.size(); ++i) {
        
        bool is_cache_hit = false;

        vector<string>::iterator min_iter;
        
        // hit 확인        
        for (vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter) {
            if (*iter == cities[i]) {
                is_cache_hit = true;
                min_iter = iter;
                break;
            }
        }

        
        // hit 했으면 1 추가
        // 기존 것 지우고 뒤에 추가 (LRU)
        if (is_cache_hit) {
            v.erase(min_iter);
            v.push_back(cities[i]);
            answer++;

        // hit 안했으면 5 추가
        // 맨 앞 지우고 뒤에 추가 (LRU)
        } else {
            
            if (v.size() == cacheSize) {
                v.erase(v.begin());
            }
            v.push_back(cities[i]);
            answer += 5;
        }
    }

    return answer;
}

int main(void) {

    int cacheSize = 5;
    vector<string> cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};

    int result = solution(cacheSize, cities);
    
    cout << result << endl;

    return 0;
}
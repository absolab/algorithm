#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {

    int answer = 0;

    // 인용된 순으로 오름차순 정렬
    sort(citations.begin(), citations.end());

    for (int i=0; i<citations.size(); ++i) {

        // H index 조건 확인 (큰 값부터)
        if (citations.size() - i <= citations[i]) { 

            answer = citations.size() - i;
            break;
        }
    }

    return answer;
}

int main(void) {

    vector<int> citations = {3, 0, 6, 1, 5};

    int result = solution(citations);
    cout << result << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {

    vector<int> answer;

    // 너비 + 높이 (테두리 / 2 + 반으로 잘린 놈 2개)
    int width_heigth = brown / 2 + 2;

    // 최소 너비는 3
    for (int i=3; i<width_heigth; ++i) {
        int heigth = i;
        int width = width_heigth - i;

        // 테두리를 제외한 너비 == 노란색
        if ( (heigth-2) * (width-2) == yellow) {
            answer.push_back(width);
            answer.push_back(heigth);
            break;
        }
    }

    return answer;
}

int main(void) {

    int brown = 8;
    int yellow = 1;

    vector<int> result = solution(brown, yellow);

    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
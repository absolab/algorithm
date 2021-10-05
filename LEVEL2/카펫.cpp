#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {

    vector<int> answer;

    int width_heigth = brown / 2 + 2;

    for (int i=3; i<width_heigth; ++i) {
        int heigth = i;
        int width = width_heigth - i;

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
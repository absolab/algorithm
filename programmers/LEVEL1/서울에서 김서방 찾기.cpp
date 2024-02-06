#include <string>
#include <vector>
#include <iostream>

#include <cstdio>
using namespace std;

string solution(vector<string> seoul) {

    string answer = "";

    for (int i=0; i < seoul.size(); ++i) {

        if (seoul[i] == "Kim") {
            char buffer[255];
            sprintf(buffer, "김서방은 %d에 있다", i);
            answer = buffer;
            break;
        }
    }

    return answer;
}

int main(void) {

    vector<string> seoul = {"Jane", "Kim"};

    string result = solution(seoul);

    cout << result << endl;

    return 0;
}
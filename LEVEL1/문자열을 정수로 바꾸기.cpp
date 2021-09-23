#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {

    int answer = 0;
    answer = atoi(s.c_str());

    return answer;
}


int main(void) {

    string s = "-1234";

    int result = solution(s);

    cout << result << endl;

    return 0;
}
#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(int n) {

    string answer = "";

    string str1 = "수";
    string str2 = "수박";
    string str4 = "수박수박";

    for (int i=0; i<n/4; ++i) {
        answer += str4;
    }

    switch (n%4) {
        case 1:
            answer += str1;
            break;
        case 2:
            answer += str2;
            break;
        case 3:
            answer += str2;
            answer += str1;
            break;
    }

    return answer;
}

int main(void) {

    int n = 10;

    string result = solution(n);

    cout << result << endl;

    return 0;
}
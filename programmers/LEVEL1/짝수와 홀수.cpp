#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int num) {

    string answer = "";

    if (num % 2 == 0) {

        answer = "Even";

    } else {

        answer = "Odd";
        
    }

    return answer;
}

int main(void) {

    int num = 3;

    string result = solution(num);

    cout << result << endl;

    return 0;
}
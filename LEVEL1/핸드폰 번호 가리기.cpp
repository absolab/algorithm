#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {

    string answer = "";

    for (int i=0; i<phone_number.size(); ++i) {
        if (i < phone_number.size() - 4) {
            phone_number[i] = '*';
        }
    }

    answer = phone_number;
    
    return answer;
}

int main(void) {

    string phone_number = "01033334444";

    string result = solution(phone_number);

    cout << result << endl;

    return 0;
}
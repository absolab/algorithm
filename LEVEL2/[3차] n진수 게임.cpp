#include <vector>
#include <string>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {

    string answer = "";

    // 일단 시뮬로 풀어보자
    string str = "0";

    for (int i=1; i<t*m; ++i) {

        int num = i;
        vector<char> my_stack;

        while (num != 0) {
            int temp = num % n;

            if (temp >= 10) {
                my_stack.push_back('A' + temp - 10);
            } else {
                my_stack.push_back('0' + temp);
            }

            num /= n;
        }

        while (my_stack.size() != 0) {

            str.push_back(my_stack.back());
            my_stack.pop_back();
        }
    }
    
    for (int i=0; i<t; ++i) {
        answer.push_back(str[p-1 + i*m]);
    }

    return answer;
}

int main(void) {

    int n=2, t=4, m=2, p=1;
    string result = solution(n, t, m, p);

    cout << result << endl;

    return 0;
}
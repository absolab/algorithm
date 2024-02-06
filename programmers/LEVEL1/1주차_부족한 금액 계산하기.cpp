#include <iostream>

using namespace std;

long long solution(int price, int money, int count) {

    long long answer = 0;

    long long need_money = 0;

    for (int i=1; i<=count; ++i) {
        need_money += price*i;
    }

    answer = need_money - money;

    if (answer < 0) answer = 0;

    return answer;
}

int main(void) {

    int price = 3;
    int money = 20;
    int count = 4;
    
    long long result = solution(price, money, count);

    cout << result << endl;
}
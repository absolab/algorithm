#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

vector<int> numbers_v;
vector<int> v;
bool check[7];

bool prime_numbers[10000000];
int my_numbers[10000000];

void dfs() {

    int num = 0;
    for (int i=0; i<v.size(); ++i) {
        num *= 10;
        num += v[i];
    }
    ++my_numbers[num];

    for (int i=0; i<numbers_v.size(); ++i) {
        if (check[i] == false) {
            v.push_back(numbers_v[i]);
            check[i] = true;
            dfs();
            check[i] = false;
            v.pop_back();
        }
    }
}

int solution(string numbers) {

    int answer = 0;

    // 수소 찾기 (false == 수소)
    prime_numbers[1] = true;
    for (int i=2; i<10000000; ++i) {
        for (int j=i+i; j<10000000; j+=i) {
            prime_numbers[j] = true;
        }
    }

    for (int i=0; i<numbers.size(); ++i) {
        numbers_v.push_back(numbers[i] - '0');
    }

    dfs();

    for (int i=1; i<10000000; ++i) {
        if (my_numbers[i] != 0 && prime_numbers[i] == false) {
            ++answer;
        }
    }

    return answer;
}

int main(void) {

    string numbers = "17";

    int result = solution(numbers);

    cout << result << endl;

    return 0;
}
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

    // 숫자 조각을 하나의 숫자로 변경
    for (int i=0; i<v.size(); ++i) {
        num *= 10;
        num += v[i];
    }

    ++my_numbers[num];

    // dfs부분
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

    // 소수 찾기 (false == 소수)
    prime_numbers[1] = true;
    for (int i=2; i<10000000; ++i) {
        for (int j=i+i; j<10000000; j+=i) {
            prime_numbers[j] = true;
        }
    }

    // 문자열로 들어온 숫자들을 int형으로 변환
    for (int i=0; i<numbers.size(); ++i) {
        numbers_v.push_back(numbers[i] - '0');
    }

    // 숫자들로 만들 수 있는 숫자 조합 구하기
    dfs();

    // 만들 수 있는 숫자 이면서 소수인 수가 있으면 개수 추가
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
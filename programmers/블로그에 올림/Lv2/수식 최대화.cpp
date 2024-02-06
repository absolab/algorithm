#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 절대값 구하기
// long long _abs64(long long input) {
//     return (input < 0) ? input * -1 : input;
// }

vector<long long> numbers;          // 숫자 저장
vector<char> operators;             // 연산자 저장

// 간단 계산 함수
inline long long calc2(long long num1, char op, long long num2) {
    return (op == '+') ? num1+num2 : ((op == '-') ? num1-num2 : num1*num2);
}

// 우선순위에 따라 연산
long long calc(char * op) {

    // 숫자, 연산자 복사본 생성
    vector<long long> copy_numbers = numbers;
    vector<char> copy_operators = operators;

    for (int j=0; j<3; ++j) {
        for (int i=0; i<copy_operators.size(); ++i) {
            if (copy_operators[i] == op[j]) {
                long long temp = calc2(copy_numbers[i], op[j], copy_numbers[i+1]);
                // 계산 될 숫자 제거
                copy_numbers.erase(copy_numbers.begin() + i);
                copy_numbers.erase(copy_numbers.begin() + i);
                // 계산 된 숫자 삽입 
                copy_numbers.insert(copy_numbers.begin() + i, temp);
                // 연산자 제거
                copy_operators.erase(copy_operators.begin() + i--);
            }
        }
    }
    
    return _abs64(copy_numbers[0]);
}

long long solution(string expression) {

    long long answer = 0;
    vector<string> sep;

    int pre_c_pos = 0;
    
    // 숫자와 연산자 분리
    for (int i=1; i<expression.size(); ++i) {

        char c = expression[i];

        // 숫자가 아니면 이전 연산자 위치부터 지금 위치 사이의 숫자를 저장
        if (c < '0' || c > '9') {
            numbers.push_back(stoi(expression.substr(pre_c_pos, i-pre_c_pos)));
            operators.push_back(c);
            pre_c_pos = i+1;
        }
    } numbers.push_back(stoi(expression.substr(pre_c_pos, expression.size()-pre_c_pos)));

    // 우선순위 조합의 개수는 6개 밖에 되지 않으므로 수기작성
    char op[6][3] = { {'+', '-', '*'}, {'+', '*', '-'},
                     {'-', '+', '*'}, {'-', '*', '+'},
                     {'*', '+', '-'}, {'*', '-', '+'}};

    // 우선순위에 따른 결과값 저장
    long long result;
    for (int i=0; i<6; ++i) {
        result = calc(op[i]);
        answer = (answer > result) ? answer : result;
    }

    return answer;
}

int main(void) {
 
    string expression = "100-200*300-500+20";

    int result = solution(expression);
    
    cout << result << endl;

    return 0;
}
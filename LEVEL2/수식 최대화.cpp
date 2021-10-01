#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
long long _abs64(long long input) {
    return (input < 0) ? input * -1 : input;
} */

long long solution(string expression) {

    long long answer = 0;
    vector<string> sep;

    vector<long long> numbers;
    vector<char> operators;

    int pre_c_pos = 0;
    
    // 숫자 연산자 분리
    for (int i=1; i<expression.size(); ++i) {
        char c = expression[i];

        if (c < '0' || c > '9') {
            numbers.push_back(stoi(expression.substr(pre_c_pos, i-pre_c_pos)));
            operators.push_back(c);
            pre_c_pos = i+1;
        }
    } numbers.push_back(stoi(expression.substr(pre_c_pos, expression.size()-pre_c_pos)));

    vector<long long> copy_numbers;
    vector<char> copy_operators;
    // + > - > *
    copy_numbers = numbers;
    copy_operators = operators;
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '+') {
            long long temp = copy_numbers[i] + copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '-') {
            long long temp = copy_numbers[i] - copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '*') {
            long long temp = copy_numbers[i] * copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    if (answer < _abs64(copy_numbers[0])) answer = _abs64(copy_numbers[0]);
    
    // + > * > -
    copy_numbers = numbers;
    copy_operators = operators;
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '+') {
            long long temp = copy_numbers[i] + copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '*') {
            long long temp = copy_numbers[i] * copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '-') {
            long long temp = copy_numbers[i] - copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    if (answer < _abs64(copy_numbers[0])) answer = _abs64(copy_numbers[0]);

    // - > + > *
    copy_numbers = numbers;
    copy_operators = operators;
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '-') {
            long long temp = copy_numbers[i] - copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '+') {
            long long temp = copy_numbers[i] + copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '*') {
            long long temp = copy_numbers[i] * copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    if (answer < _abs64(copy_numbers[0])) answer = _abs64(copy_numbers[0]);

    // - > * > +
    copy_numbers = numbers;
    copy_operators = operators;
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '-') {
            long long temp = copy_numbers[i] - copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '+') {
            long long temp = copy_numbers[i] + copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '*') {
            long long temp = copy_numbers[i] * copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    if (answer < _abs64(copy_numbers[0])) answer = _abs64(copy_numbers[0]);
    
    // * > + > -
    copy_numbers = numbers;
    copy_operators = operators;
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '*') {
            long long temp = copy_numbers[i] * copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '+') {
            long long temp = copy_numbers[i] + copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '-') {
            long long temp = copy_numbers[i] - copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    if (answer < _abs64(copy_numbers[0])) answer = _abs64(copy_numbers[0]);

    // * > - > +
    copy_numbers = numbers;
    copy_operators = operators;
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '*') {
            long long temp = copy_numbers[i] * copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '-') {
            long long temp = copy_numbers[i] - copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    for (int i=0; i<copy_operators.size(); ++i) {
        if (copy_operators[i] == '+') {
            long long temp = copy_numbers[i] + copy_numbers[i+1];
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.erase(copy_numbers.begin() + i);
            copy_numbers.insert(copy_numbers.begin() + i, temp);
            copy_operators.erase(copy_operators.begin() + i--);
        }
    }
    if (answer < _abs64(copy_numbers[0])) answer = _abs64(copy_numbers[0]);

    return answer;
}

int main(void) {
 
    string expression = "100-200*300-500+20";

    int result = solution(expression);
    
    cout << result << endl;

    return 0;
}
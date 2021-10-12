#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {

    vector<long long> answer;

    for (int i=0; i<numbers.size(); ++i) {

        long long num = numbers[i];
        if (num % 4 == 3) {
            long long copy_num = num;
            long long d = 1;
            while (1) {
                if (copy_num % 4 == 1) {
                    answer.push_back(num + d);
                    break;
                } else {
                    copy_num /= 2;
                    d *= 2;
                }
            }
        } else {
            answer.push_back(num + 1);
        }
    }
    
    return answer;
}

int main(void) {

    vector<long long> numbers = {3, 4, 5, 6};
    vector<long long> result = solution(numbers);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
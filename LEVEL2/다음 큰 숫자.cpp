#include <vector>
#include <string>
#include <iostream>

using namespace std;

int get_one_count (int n) {

    int result = 0;

    while(n != 0 ) {
        result += (n % 2 == 0) ? 0 : 1;
        n /= 2;    
    }

    return result;
}

int solution(int n) {

    int answer = 0;

    int n_count = get_one_count(n);

    int n2 = n+1;
    while (get_one_count(n2) != n_count) {
        n2++;
    }

    answer = n2;

    return answer;
}

int main(void) {

    int n = 78;
    int result = solution(n);

    cout << result << endl;

    return 0;
}
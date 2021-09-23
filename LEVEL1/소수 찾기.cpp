#include <string>
#include <vector>
#include <iostream>


using namespace std;

bool check[1000001];

int solution(int n) {

    int answer = 0;

    for (int i=2; i<=1000000; ++i) {

        for (int j=i+i; j<=1000000; j+=i) {

            check[j] = true;
        }
    }

    for (int i=2; i<=n; ++i) {
        if (check[i] == false) ++answer;
    }

    return answer;
}

int main(void) {

    int n = 10;

    int result = solution(n);

    cout << result << endl;

    return 0;
}
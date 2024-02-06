#include <iostream>

using namespace std;

int solution(int n) {
    
    int ans = 1;

    // 끝에서 되돌아오는 방식
    while (n != 1) {
        // 2의 배수가 아니면 1칸 이동하고 나누기 2
        if (n % 2 == 1) {
            ans++;
        }
        n/=2;
    }
    
    return ans;
}

int main(void) {

    int n = 5000;
    int result = solution(n);

    cout << result << endl;

    return 0;
}
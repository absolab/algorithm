#include <vector>
#include <string>
#include <iostream>

using namespace std;

long long solution(int w,int h) {

    long long answer = 1;

    // 가로가 짧고 세로가 길도록 설정 (Swap)
    if (w > h) { int temp = w; w = h; h = temp; }

    // 유클리드 호제법을 이용하여 최소공배수를 구함
    int gcd = w;
    int temp = h;
    while(1) {

        int r = temp % gcd;
        if (r == 0) { break; }

        temp = gcd;
        gcd = r;        
    }

    // 작은 사각형으로 만들기
    int small_w = w / gcd;
    int small_h = h / gcd;

    // 대각선이 지나가는 사각형의 개수 구하기
    int next_y = 1;
    int count = 0;    

    for (int x=1; x <= small_h; ++x) {

        long long y = ((long long)x*small_w) / small_h;
        long long y_r = ((long long)x*small_w) % small_h;

        if (y_r == 0) {
            ++count;
            ++next_y;
        } else if (y - next_y < 0) {
            ++count;
        } else { // y-next_y > 0
            count += 2;
            ++next_y;
        }
    }
    
    answer = ((long long)w * h) - (long long)count * gcd;

    return answer;
}

int main(void) {

    long long w = 8;
    long long h = 12;

    long long result = solution(w, h);

    cout << result << endl;

    return 0;
}


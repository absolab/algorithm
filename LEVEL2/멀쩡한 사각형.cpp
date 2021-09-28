#include <vector>
#include <string>
#include <iostream>

using namespace std;

long long solution(int w,int h) {

    long long answer = 1;

    if (w > h) {
        int temp = w;
        w = h;
        h = temp;
    }

    int gcd = w;
    int temp = h;

    while(1) {

        int r = temp % gcd;
        if (r == 0) break; 

        temp = gcd;
        gcd = r;        
    }

    int small_w = w / gcd;
    int small_h = h / gcd;

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

    answer = ((long long)w * h) - (long long)gcd * count;

    return answer;
}

int main(void) {

    long long w = 8;
    long long h = 12;

    long long result = solution(w, h);

    cout << result << endl;

    return 0;
}


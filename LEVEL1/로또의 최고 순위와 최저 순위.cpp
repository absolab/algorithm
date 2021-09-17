#include <iostream>
using namespace std;

#define MAX 46

int main() {

    int lottos[] = {45, 4, 35, 20, 3, 9};
    int win_nums[] = {20, 9, 3, 45, 4, 35};

    int myLottos[6];

    // 정렬   
    for (int i=0; i<6; ++i) {

        int min = MAX;
        int loc = 0;

        for (int j=0; j<6; ++j) {

            if (min > lottos[j]) {
                loc = j;
                min = lottos[j];
            }
        }

        lottos[loc] = MAX;
        myLottos[i] = min;
    }

    // 같은 값의 개수
    int equal_count = 0;
    int zero_count = 0;
    for (int i=0; i<6; ++i) {

        if (myLottos[i] == 0) {
            ++zero_count;
            continue;
        }

        for (int j=0; j<6; ++j) {
            if (myLottos[i] == win_nums[j]) {
                ++equal_count;
                break;
            }
        }
    }

    // 최저 순위 결정
    int min_rank;
    if (equal_count <= 1) {
        min_rank = 6;
    } else {
        min_rank = 7 - equal_count;
    }

    // 최고 순위
    int max_rank;
    if (min_rank <=zero_count) {
        max_rank = 1;
    } else {
        max_rank = min_rank - zero_count;
    }

    cout << "[" << max_rank << ", " << min_rank << "]" << endl;



    return 0;
}
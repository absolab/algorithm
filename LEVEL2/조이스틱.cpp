#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(string name) {

    int answer = 0;

    for (int i=0; i<name.size(); ++i) {
        int num1 = name[i] - 'A';
        int num2 = 'Z' + 1 - name[i];
        int num3 = (num1 < num2) ? num1 : num2;
        answer += num3;
    }

    // 1. �������� Ž��
    int move_left = 0;
    int temp = 0;
    for (int i=name.size()-1; i>=1; --i) {
        if (name[i] == 'A') {
            ++temp;
        } else {
            move_left += temp + 1;
            temp = 0;
        }
    }

    // 2. ���������� Ž��
    int move_right = 0;
    temp = 0;
    for (int i=1; i<name.size(); ++i) {
        if (name[i] == 'A') {
            ++temp;
        } else {
            move_right += temp + 1;
            temp = 0;
        }
    }

    name[0] = 'A';
    // 3. ���������� ���ٰ� �������� Ž��
    int move_right_and_left = 999;
    // ���� ��ġ
    for (int i=1; i<name.size(); ++i) {
        int move = 0;
        move = i + i;
        temp = 0;
        for (int j=name.size()-1; j>i; --j) {
            if (name[j] == 'A') {
                ++temp;
            } else {
                move += temp + 1;
                temp = 0;
            }
        }
        if (move_right_and_left > move) move_right_and_left = move;
    }

    int min = move_left;
    if (min > move_right) min = move_right;
    if (min > move_right_and_left) min = move_right_and_left;

    answer += min;

    return answer;
}

int main(void) {

    string name = "ZAAAZZZZZZZ";
    int result = solution(name);
  
    cout << result << endl;
 
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define RIGHT "right"
#define LEFT  "left"

string solution(vector<int> numbers, string hand) {

    // 입력할 숫자를 좌표로 변환
    vector<pair<int,int>> pos_numbers;
    for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
        
        int number = *iter;

        if (number == 0) {
            pos_numbers.push_back(pair<int,int>(3,1));
        } else {
            pos_numbers.push_back(pair<int,int>((number-1)/3 , (number-1)%3));
        }
    }

    pair<int,int> pos_left_hand = pair<int,int>(3,0);
    pair<int,int> pos_right_hand = pair<int,int>(3,2);
    string answer = "";

    for (vector<pair<int,int>>::iterator iter = pos_numbers.begin(); iter != pos_numbers.end(); ++iter) {

        // 1, 4, 7
        if ((*iter).second == 0) {

            answer.push_back('L');
            pos_left_hand = *iter;

        // 3, 6, 9
        } else if ((*iter).second == 2) {

            answer.push_back('R');
            pos_right_hand = *iter;

        // 2, 5, 8, 0
        } else {

            int dist_left_hand  = abs((*iter).first - pos_left_hand.first)  + abs((*iter).second - pos_left_hand.second);
            int dist_right_hand = abs((*iter).first - pos_right_hand.first) + abs((*iter).second - pos_right_hand.second);

            if (dist_left_hand < dist_right_hand) {

                answer.push_back('L');
                pos_left_hand = *iter;

            } else if (dist_left_hand == dist_right_hand) {

                if (hand == LEFT) {

                    answer.push_back('L');
                    pos_left_hand = *iter;

                } else {

                    answer.push_back('R');
                    pos_right_hand = *iter;

                }

            } else {

                answer.push_back('R');
                pos_right_hand = *iter;
            }
        }
    }

    return answer;
}

int main(void) {

    //vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    //string hand = RIGHT;

    vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    string hand = LEFT;

    //vector <int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    //string hand = RIGHT;

    cout << solution(numbers, hand) << endl;

    return 0;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {

    vector<int> answer;

    int user1_answer[] = {1, 2, 3, 4, 5};
    int user1_answer_count = 5;
    int user1_correct_count = 0;

    int user2_answer[] = {2, 1, 2, 3, 2, 4, 2, 5,};
    int user2_answer_count = 8;
    int user2_correct_count = 0;

    int user3_answer[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int user3_answer_count = 10;
    int user3_correct_count = 0;

    for (int i=0; i<answers.size(); ++i) {

        if (answers[i] == user1_answer[i % user1_answer_count]) {
            ++user1_correct_count;
        }

        if (answers[i] == user2_answer[i % user2_answer_count]) {
            ++user2_correct_count;
        }

        if (answers[i] == user3_answer[i % user3_answer_count]) {
            ++user3_correct_count;
        }
    }

    int max = -1;
    if (max <= user1_correct_count) {
        answer.push_back(1);
        max = user1_correct_count;
    }

    if (max == user2_correct_count) {
        answer.push_back(2);
    } else if (max < user2_correct_count) {
        answer.clear();
        answer.push_back(2);
        max = user2_correct_count;
    }

    if (max == user3_correct_count) {
        answer.push_back(3);
    } else if (max < user3_correct_count) {
        answer.clear();
        answer.push_back(3);
        max = user3_correct_count;
    }

    return answer;
}

int main(void) {

    vector<int> answers = {1,2,3,4,5};

    vector<int> result = solution(answers);

    for (int i=0; i<result.size(); ++i) {

        cout << result[i] << " ";
    } cout << endl;

    return 0;
}
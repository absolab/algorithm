#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {

    string::iterator iter;

    // 1단계: 대문자 > 소문자
    // 2단계: 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)제외한 모든 문자 제거
    for (iter = new_id.begin(); iter != new_id.end(); ++iter) {
        
        char c = *iter;
        bool  check_level_2 = false;

        c = tolower(c);
        
        if (c >= 'a' && c <= 'z') {

            check_level_2 = true;

        } else if (c >= '0' && c <= '9') {

            check_level_2 = true;

        } else if (c == '-' || c == '_' || c=='.') {

            check_level_2 = true;
        }

        if (check_level_2) {
            *iter = c;
        } else {
            new_id.erase(iter);
            --iter;
        }
    }

    // 3단계: 마침표(.)가 2번 이상 연속이면 하나로 치환
    for (iter = new_id.begin() + 1; iter != new_id.end(); ++iter) {

        if (*iter == '.' && *(iter - 1) == '.') {

            new_id.erase(iter);
            iter--;
        }
    }

    // 4단계: 마침표(.)가 처음이나 끝에 있으면 제거
    while(true) {
        iter = new_id.begin();
        if (*iter == '.') {
            new_id.erase(iter);    
        } else {
            break;
        }
    }
    while(true) {
        iter = new_id.end() - 1;
        if (*iter == '.') {
            new_id.erase(iter);
        } else {
            break;
        }
    }

    // 5단계: 빈 문자열이면 a대입
    if (new_id.length() == 0) {
        new_id = "a";
    }

    // 6단계: 16자 이상이면 15자에서 끊고, 마지막 글자가 마침표면 또한 제거
    new_id = new_id.substr(0, 15);
    while(true) {
        iter = new_id.end() - 1;
        if (*iter == '.') {
            new_id.erase(iter);
        } else {
            break;
        }
    }

    // 7단계: 2자 이하면 마지막 문자 반복시켜 3의 길이로 만듬
    if (new_id.length() < 3) {
        new_id.push_back(new_id.back());
    }
    if (new_id.length() < 3) {
        new_id.push_back(new_id.back());
    }
    
    string answer = new_id;
    return answer;
}

int main(void) {

    string new_id[] = {
        "...!@BaT#*..y.abcdefghijklm",
        "z-+.^.",
        "=.=",
        "123_.def",
        "abcdefghijklmn.p"
    };

    cout << solution(new_id[4]) << endl;
    
}
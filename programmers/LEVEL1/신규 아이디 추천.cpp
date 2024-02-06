#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {

    string::iterator iter;

    // 1�ܰ�: �빮�� > �ҹ���
    // 2�ܰ�: ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)������ ��� ���� ����
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

    // 3�ܰ�: ��ħǥ(.)�� 2�� �̻� �����̸� �ϳ��� ġȯ
    for (iter = new_id.begin() + 1; iter != new_id.end(); ++iter) {

        if (*iter == '.' && *(iter - 1) == '.') {

            new_id.erase(iter);
            iter--;
        }
    }

    // 4�ܰ�: ��ħǥ(.)�� ó���̳� ���� ������ ����
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

    // 5�ܰ�: �� ���ڿ��̸� a����
    if (new_id.length() == 0) {
        new_id = "a";
    }

    // 6�ܰ�: 16�� �̻��̸� 15�ڿ��� ����, ������ ���ڰ� ��ħǥ�� ���� ����
    new_id = new_id.substr(0, 15);
    while(true) {
        iter = new_id.end() - 1;
        if (*iter == '.') {
            new_id.erase(iter);
        } else {
            break;
        }
    }

    // 7�ܰ�: 2�� ���ϸ� ������ ���� �ݺ����� 3�� ���̷� ����
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
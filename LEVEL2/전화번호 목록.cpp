#include <vector>
#include <string>
#include <iostream>

#include <map>
#include <algorithm>
using namespace std;

bool compare(string i, string j) { return i.size() > j.size(); }

bool solution(vector<string> phone_book) {

    bool answer = true;
    map<string , bool> check;

    sort(phone_book.begin(), phone_book.end(), compare);

    for (int i=0; i<phone_book.size(); ++i) {
        string s = phone_book[i];
        if (check.find(s) == check.end()) {
            for (int i=1; i<=s.size(); ++i) {
                check.insert(make_pair(s.substr(0, i), true));
            }
        } else {
            answer = false;
            break;
        }
    }

    return answer;
}

int main(void) {

    vector<string> phone_book = {"119", "97674223", "1195524421"};

    bool result = solution(phone_book);

    cout << result << endl;

    return 0;
}
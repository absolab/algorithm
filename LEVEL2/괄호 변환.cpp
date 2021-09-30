#include <vector>
#include <string>
#include <iostream>

using namespace std;

string seperate(string p) {

    if (p.size() == 0) {
        return "";
    }

    string u = "";
    string v = "";

    int score = 0;
    for (int i=0; i<p.size(); ++i) {
        if (p[i] == '(') {
            score += 1;
        } else {
            score -= 1;
        }

        if (score == 0) {
            u = p.substr(0, i + 1);
            v = p.substr(i+1, p.size()-i);
            break;
        }
    }

    score = 0;
    bool is_correct_str = true;
    for (int i=0; i<u.size(); ++i) {
        if (u[i] == '(') {
            score += 1;
        } else {
            score -= 1;
        }
        
        if (score < 0) {
            is_correct_str = false;
        }
    }

    string w = "";
    if (is_correct_str == true) {
        w += u;
        w += seperate(v);
    } else {
        w += '(';
        w += seperate(v);
        w += ')';
        for (int i=1; i<u.size()-1; ++i) {
            if (u[i] == '(') {
                w += ')';
            } else {
                w += '(';
            }
        }
    }
    return w;
}

string solution(string p) {
    
    string answer = "";
    if (p == "") return "";

    answer = seperate(p);

    
    return answer;
}

int main(void) {

    string p = "()))((()";
    string result = solution(p);

    cout << result << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(string word) {

    int answer = 0;

    char c = word[0];

    int weight = 781;
    switch(c) {
    case 'A':
        answer += 1;
        break;
    case 'E':
        answer += weight + 1;
        break;
    case 'I':
        answer += weight*2 + 1;
        break;
    case 'O':
        answer += weight*3 + 1;
        break;
    case 'U':
        answer += weight*4 + 1;
        break;
    }

    if (word.size() >= 2) {
        c = word[1];
        weight = 156;
        switch(c) {
        case 'A':
            answer += 1;
            break;
        case 'E':
            answer += weight + 1;
            break;
        case 'I':
            answer += weight*2 + 1;
            break;
        case 'O':
            answer += weight*3 + 1;
            break;
        case 'U':
            answer += weight*4 + 1;
            break;
        }
    }

    if (word.size() >= 3) {
        c = word[2];
        weight = 31;
        switch(c) {
        case 'A':
            answer += 1;
            break;
        case 'E':
            answer += weight + 1;
            break;
        case 'I':
            answer += weight*2 + 1;
            break;
        case 'O':
            answer += weight*3 + 1;
            break;
        case 'U':
            answer += weight*4 + 1;
            break;
        }
    }

    if (word.size() >= 4) {
        c = word[3];
        weight = 6;
        switch(c) {
        case 'A':
            answer += 1;
            break;
        case 'E':
            answer += weight + 1;
            break;
        case 'I':
            answer += weight*2 + 1;
            break;
        case 'O':
            answer += weight*3 + 1;
            break;
        case 'U':
            answer += weight*4 + 1;
            break;
        }
    }

    if (word.size() >= 5) {
        c = word[4];
        weight = 1;
        switch(c) {
        case 'A':
            answer += 1;
            break;
        case 'E':
            answer += weight + 1;
            break;
        case 'I':
            answer += weight*2 + 1;
            break;
        case 'O':
            answer += weight*3 + 1;
            break;
        case 'U':
            answer += weight*4 + 1;
            break;
        }
    }

    return answer;
}

int main(void) {

    string word = "AAAAE";
    int result = solution(word);
 
    cout << result << endl;

   return 0;
}
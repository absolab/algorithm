#include <string>
#include <vector>

#include <iostream>
using namespace std;

string solution(int a, int b) {

    string answer = "";

    int date = 0;

    switch(a) {
        case 1:
            break;
        case 2:
            date += 31;
            break;
        case 3:
            date += 60;
            break;
        case 4:
            date += 91;
            break;
        case 5:
            date += 121;
            break;
        case 6:
            date += 152;
            break;
        case 7:
            date += 182;
            break;
        case 8:
            date += 213;
            break;
        case 9:
            date += 244;
            break;
        case 10:
            date += 274;
            break;
        case 11:
            date += 305;
            break;
        case 12:
            date += 335;
            break;
    }

    date += b;

    switch(date % 7) {
        case 0:
            answer = "THU";
            break;
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
    }

    return answer;
}

int main(void) {

    int a = 5;
    int b = 24;

    string result = solution(a, b);

    cout << result << endl;

    return 0;
}
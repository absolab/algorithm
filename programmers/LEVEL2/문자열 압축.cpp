#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(string s) {

    int answer = 9999;

    string result = "";

    for (int i=1; i<=s.size(); ++i) {

        int start_pos = 0;
        int compress_count = 0;
        string pre_str = "";

        while(1) {

            string str = "";

            if (start_pos + i >= s.size()) {

                str = s.substr(start_pos, s.size()-start_pos);
                
            } else {
                str = s.substr(start_pos, i);
            }

            start_pos += i;
            if (pre_str == str) {

                ++compress_count;

            } else if (pre_str != "") {

                if (compress_count > 1) {
                    
                    result += to_string(compress_count);
                }
                result += pre_str;

                pre_str = str;
                compress_count = 1;

            } else { // pre_str == ""

                pre_str = str;
                compress_count = 1;
            }

            if (str.size() < i) {
                result += str;   
                break;
            }
        }

        if (result.size() < answer) {

            answer = result.size();
        }

        result.clear();
    }

    return answer;
}

int main(void) {

    string s = "abcabcabcabcdededededede";
    int result = solution(s);

    cout << result << endl;

    return 0;
}
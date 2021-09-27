#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
#include <map>
using namespace std;

int solution(int n, vector<string> data) {

    int answer = 0;

    bool is_visited[8] = {0, };
    vector<int> line = {0, 1, 2, 3, 4, 5, 6, 7};
    map<char, int> char_to_int;

    char_to_int.insert(make_pair('A', 0));
    char_to_int.insert(make_pair('C', 1));
    char_to_int.insert(make_pair('F', 2));
    char_to_int.insert(make_pair('J', 3));
    char_to_int.insert(make_pair('M', 4));
    char_to_int.insert(make_pair('N', 5));
    char_to_int.insert(make_pair('R', 6));
    char_to_int.insert(make_pair('T', 7));
    
    do {
        bool is_satisfied = true;

        for (int i=0; i<n; ++i) {
            
            int friend1 = char_to_int[data[i][0]];
            int friend2 = char_to_int[data[i][2]];
            int friend1_pos, friend2_pos;

            for (int j=0; j<8; ++j) {
                if (line[j] == friend1) friend1_pos = j;
                if (line[j] == friend2) friend2_pos = j;
            }

            int gap = abs(friend1_pos - friend2_pos);
            int want_gap = data[i][4] - '0' + 1;
            char c = data[i][3];

            if (c == '=' && gap != want_gap) {
                is_satisfied = false;
            } else if (c == '>' && gap <= want_gap) {
                is_satisfied = false;
            } else if (c == '<' && gap >= want_gap) {
                is_satisfied = false;
            }
        }

        if (is_satisfied) {
            ++answer;
        }
    } while(next_permutation(line.begin(), line.end()));

    return answer;
}

int main(void) {

    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};

    int result = solution(n, data);

    cout << result << endl;

    return 0;
}
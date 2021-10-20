#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {

    vector<int> answer;

    long long row1 = left/n;
    long long col1 = left%n;
    long long row2 = right/n;
    long long col2 = right%n;

    for (long long i = row1; i <= row2; ++i) {    
        
        for (long long j = 0; j < n; ++j) {

            if (i == row1 && j < col1) continue;
            if (i == row2 && j > col2) break;

            if (j+1 < i+1) {
                answer.push_back(i+1);
            } else {
                answer.push_back(j+1);
            }
        }
        
    }    

    return answer;
}

int main(void) {

    int n = 3;
    
    long long left = 2;
    long long right = 5;
 
    vector<int> result = solution(n, left, right);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
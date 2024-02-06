#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {

    vector<int> answer;

    // left와 right를 n*n 행렬에서의 좌표로 변경
    long long row1 = left / n;  
    long long col1 = left % n;  
    long long row2 = right / n; 
    long long col2 = right % n; 


    // 실제로 배열을 만들지 않고, 각각의 요소를 계산하여 집어넣음
    for (long long i = row1; i <= row2; ++i) {            
        for (long long j = 0; j < n; ++j) {

            // 버려야 하는 맨 앞 부분
            if (i == row1 && j < col1) continue;
            // 버려야 하는 맨 뒷 부분
            if (i == row2 && j > col2) break;

            // 원래 행렬의 i와 j를 갖고 계산 하기 때문에 계산이 쉽다
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
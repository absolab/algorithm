#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<vector<int>> v;

pair<int,int> func (int row, int col, int size) {

    int num = v[row][col];
    bool check = true;

    int zero_count = 0;
    int one_count = 0;

    if (size == 1) {
        if (num == 0) return make_pair(1, 0);
        else return make_pair(0, 1);
    }


    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {

            if (v[row+i][col+j] != num) {
                check = false;
                break;
            }
        }
        if (check == false) {
            break;
        }
    }

    if (check) {
        if (num == 0) {
            zero_count++;
        } else {
            one_count++;
        }
    } else {
        int new_size = size / 2;
        pair<int,int> pair[4];
        pair[0] = func(row, col, new_size);
        pair[1] = func(row+new_size, col, new_size);
        pair[2] = func(row, col+new_size, new_size);
        pair[3] = func(row+new_size, col+new_size, new_size);
        
        for (int i=0; i<4; ++i) {
            zero_count += pair[i].first;
            one_count += pair[i].second;
        }
    }
    return make_pair(zero_count, one_count);
}

vector<int> solution(vector<vector<int>> arr) {

    vector<int> answer;

    v = arr;
    
    pair<int,int> temp = func(0,0,arr.size());
    answer.push_back(temp.first);
    answer.push_back(temp.second);

    return answer;
}

int main(void) {

    vector<vector<int>> arr = {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};
    vector<int> result = solution(arr);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

    vector<int> answer;

    for (vector<vector<int>>::iterator iter = commands.begin(); iter != commands.end(); ++iter) {

        vector<int> command = *iter;

        int begin = command[0];
        int end = command[1];
        int pos = command[2];

        vector<int> temp_array;
        temp_array.assign(array.begin()+begin-1, array.begin()+end);

        sort(temp_array.begin(), temp_array.end());

        answer.push_back(temp_array[pos-1]);
    }
  
    return answer;
}

int main(void) {

    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> answer = solution(array, commands);
    
    for (vector<int>::iterator iter = answer.begin(); iter != answer.end(); ++iter) {

        cout << *iter << " ";

    } cout << "\n";

    return 0;
}
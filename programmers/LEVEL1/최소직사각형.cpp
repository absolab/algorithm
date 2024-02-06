#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int answer = 0;

    int max_width = 0;
    int max_height = 0;

    for (int i=0; i<sizes.size(); ++i) {

        vector<int> v = sizes[i];

        int width, height;

        width = min(v[0], v[1]);
        height = max(v[0], v[1]);

        max_width = max(max_width, width);
        max_height = max(max_height, height);
    }

    answer = max_width * max_height;

    return answer;
}

int main(void) {

    vector<vector<int>> sizes = {{60, 50},{30, 70},{60, 30},{80, 40}};
    
    int result = solution(sizes);    
    cout << result << endl;

    return 0;
}
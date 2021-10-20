#include <vector>
#include <string>
#include <iostream>

#include <map>
using namespace std;

int solution(string dirs) {

    int answer = 0;

    int x=0, y=0;
    
    map<pair<pair<int,int>,pair<int,int>>, bool> path;

    for (int i=0; i<dirs.size(); ++i) {
        
        char c = dirs[i];
        pair<int,int> pre_pt = make_pair(x, y);

        switch(c) {
        case 'U':
            ++y;
            if (y == 6) {--y; continue;}
            break;
        case 'D':
            --y;
            if (y == -6) {++y; continue;}
            break;
        case 'R':
            ++x;
            if (x == 6) {--x; continue;}
            break;
        case 'L':
            --x;
            if (x == -6) {++x; continue;}
            break;
        }

        pair<int,int> pt = make_pair(x, y);

        path.insert(make_pair(make_pair(pt, pre_pt), true));
        path.insert(make_pair(make_pair(pre_pt, pt), true));
    }

    answer = path.size() / 2;

    return answer;
}

int main(void) {

    string dirs = "LLLLLUUUUURRRRRRRRRRDDDDDDDDDDLLLLLLLLLLUUUUUUUUUU"; 
    int result = solution(dirs);
 
    cout << result << endl;

    return 0;
}
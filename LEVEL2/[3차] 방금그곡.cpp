#include <vector>
#include <string>
#include <iostream>

using namespace std;

// #붙은 음을 소문자로 변경
string sharptolower(string music) {

    string result = "";

    for (int i=0; i<music.size(); ++i) {
        if (i+1 != music.size() && music[i+1] == '#') {
            result.push_back(tolower(music[i]));
            ++i;
        } else {
            result.push_back(music[i]);
        }
    }

    return result;
}

class my_music {
private:
    int full_min;
    string name = "";
    string music = "";

public:
    my_music(string musicinfo) {
        int start_hour = stoi(musicinfo.substr(0,2));
        int start_min = stoi(musicinfo.substr(3,2));
        int end_hour = stoi(musicinfo.substr(6,2));
        int end_min = stoi(musicinfo.substr(9,2));

        full_min = (end_hour - start_hour)*60 + (end_min - start_min);

        for (int i = 12; i<musicinfo.size(); ++i) {
            if (musicinfo[i] == ',') {
                music = musicinfo.substr(i+1, musicinfo.size() - i);
                break;
            }
            name.push_back(musicinfo[i]);
        }

        music = sharptolower(music);
    }

    string get_music() {return music;}
    string get_name() {return name;}
    int get_min() {return full_min;}

    string get_full_music() {

        string result = "";

        for (int i=0; i<full_min; ++i) {
            result.push_back(music[i%music.size()]);
        }

        return result; 
    }
};


string solution(string m, vector<string> musicinfos) {

    string answer = "(None)";
    int play_time = 0;

    m = sharptolower(m);

    for (int i=0; i<musicinfos.size(); ++i) {
        
        my_music mm = my_music(musicinfos[i]);
        
        string music = mm.get_music();
        string full_music = mm.get_full_music();

        for (int j=0; j<music.size(); ++j) {
            if (j + m.size() > full_music.size()) break;
            if (m == full_music.substr(j, m.size())) {
                if (play_time < mm.get_min()) {
                    play_time = mm.get_min();
                    answer = mm.get_name();
                }
            }
        }
    }

    return answer;
}

int main(void) {

    string m = "CC#BCC#BCC#BCC#B";
    vector<string> musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};

    string result = solution(m, musicinfos);

    cout << result << endl;

    return 0;
}
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class my_file {
private:
    string name = "";
    string HEAD = "";
    int NUMBER = 0;

public:
    my_file(string file) {

        name = file;

        int idx = 0;

        // HEAD
        while (idx != file.size()) {
            char c = file[idx];

            if (c >= '0' && c <= '9') {
                break;
            }

            if (c=='-' || c=='.' || c==' ') {
                HEAD.push_back(c);
            } else {
                HEAD.push_back(tolower(c));
            }
            ++idx;
        }

        // NUMBER
        while (idx != file.size()) {
            char c = file[idx];

            if (c < '0' || c > '9') {
                break;
            }

            NUMBER = NUMBER * 10 + c-'0';

            ++idx;
        }
    }

    string get_name() {
        return name;
    }

public:
    static bool compare(my_file file1, my_file file2) {
        if (file1.HEAD == file2.HEAD) {
            return file1.NUMBER < file2.NUMBER;
        }
        return (file1.HEAD < file2.HEAD);
    }
};

vector<string> solution(vector<string> files) {

    vector<string> answer;

    vector<my_file> myfile;

    for (int i=0; i<files.size(); ++i) {
        myfile.push_back(my_file(files[i]));
    }

    stable_sort(myfile.begin(), myfile.end(), my_file::compare);

    for (int i=0; i<myfile.size(); ++i) {
        answer.push_back(myfile[i].get_name());
    }

    return answer;
}

int main(void) {

    vector<string> files = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};

    vector<string> result = solution(files);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "|";
    } cout << endl;

    return 0;
}
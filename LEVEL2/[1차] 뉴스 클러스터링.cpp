#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

int solution(string str1, string str2) {

    int answer = 0;

    if (str1.size() == 0 && str2.size() == 0) {
        return 65536;
    }

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    vector<string> A, B;

    for (int i=0; i<str1.size()-1; ++i) {
        if (str1[i] < 'a' || str1[i] > 'z') { continue; }
        if (str1[i+1] < 'a' || str1[i+1] > 'z') { continue; }
        A.push_back(str1.substr(i, 2));
    }
    for (int i=0; i<str2.size()-1; ++i) {
        if (str2[i] < 'a' || str2[i] > 'z') { continue; }
        if (str2[i+1] < 'a' || str2[i+1] > 'z') { continue; }
        B.push_back(str2.substr(i, 2));
    }

    if (A.size() == 0 && B.size() == 0) {
        return 65536;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<string> v;
    string same_str = "";
    if (A.size() != 0) {
        same_str = A[0];
        v.push_back(A[0]);
    }
    int same_count = 0;

    for (int i=1; i<A.size(); ++i) {
        if (same_str == A[i]) {
            A[i] += to_string(same_count++);
        } else {
            same_count = 0;
            same_str = A[i];
        }
        v.push_back(A[i]);
    }

    same_str = "";
    if (B.size() != 0) {
        same_str = B[0];
        v.push_back(B[0]);
    }
    same_count = 0;
    for (int i=1; i<B.size(); ++i) {
        if (same_str == B[i]) {
            B[i] += to_string(same_count++);
        } else {
            same_count = 0;
            same_str = B[i];
        }
        v.push_back(B[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int inter = 0;
    for (int i=0; i<A.size(); ++i) {
        string strA = A[i];
        for (int j=0; j<B.size(); ++j) {
            string strB = B[j];
            if (A[i] == B[j]) {
                ++inter;
            }
        }
    }
    
    int union_size = v.size();

    if (union_size == 0) answer = 65536;
    else answer = (inter * 65536) / (union_size);

    return answer;
}

int main(void) {

    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";

    int result = solution(str1, str2);

    cout << result << endl;

    return 0;
}
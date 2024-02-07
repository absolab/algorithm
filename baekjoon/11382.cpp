#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  string A, B, C, result = "";
  cin >> A >> B >> C;

  int max_length = max(A.length(), max(B.length(), C.length()));

  int pre_value = 0;

  for (int i = 0; i < max_length; ++i) {

    int a = 0, b = 0, c = 0, sum = pre_value;
    pre_value = 0;

    if (A.length() > i) {
      a = A.at(A.length() - i - 1) - '0';
    }
    if (B.length() > i) {
      b = B.at(B.length() - i - 1) - '0';
    }
    if (C.length() > i) {
      c = C.at(C.length() - i - 1) - '0';
    }

    sum += a + b + c;

    pre_value = sum / 10;
    result += (char)(sum % 10 + '0');
  }

  if (pre_value != 0) {
    result += (char)(pre_value + '0');
  }

  reverse(result.begin(), result.end());
  cout << result << endl;

  return 0;
}
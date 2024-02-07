#include <iostream>

using namespace std;

int main(void) {
  int N;
  cin >> N;

  int n = N / 4;

  for (int i = 0; i < n; ++i) {
    cout << "long ";
  }
  cout << "int \n";

  return 0;
}
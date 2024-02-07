/**
 * 10810 공 넣기
 * 2024.02.07
 * Bronze 3
*/

#include <iostream>
using namespace std;

int arr[101];

int main(void) {
  int N, M;
  int i, j, k;
  cin >> N >> M;

  for (int a = 0; a < M; ++a) {
    cin >> i >> j >> k;

    for (int b = i; b <= j; ++b) {
      arr[b] = k;
    }
  }

  for (int c = 1; c <= N; ++c) {
    cout << c << " ";
  }
  return 0;
}
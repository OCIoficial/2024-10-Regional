// @ocimatic should-fail=[st2]
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int L, N, M, E;

  cin >> L >> N >> M >> E;

  vector<int> station_distance(N);
  for (int i = 0; i < N; ++i) {
    cin >> station_distance[i];
  }

  vector<int> train_positions(M, -1);

  for (int i = 0; i < E; ++i) {
    int t;
    cin >> t;

    if (t == 1) {
      int j, p;
      cin >> j >> p;

      train_positions[j - 1] = p;
    } else {
      int i;
      cin >> i;

      int d = station_distance[i - 1];

      int max = INT_MIN;
      for (int j = 0; j < M; ++j) {
        int p = train_positions[j];
        if (p != -1 && p <= d && p > max) {
          max = p;
        }
      }
      if (max == INT_MIN) {
        cout << "-1" << endl;
      } else {
        cout << (d - max) << endl;
      }
    }
  }
  return 0;
  return 0;
}

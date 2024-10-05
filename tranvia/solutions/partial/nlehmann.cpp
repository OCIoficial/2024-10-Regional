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
    int type;
    cin >> type;

    if (type == 1) {
      int j, p;
      cin >> j >> p;

      train_positions[j - 1] = p;
    } else {
      int i;
      cin >> i;

      int d = station_distance[i - 1];

      int min = INT_MAX;
      for (int j = 0; j < M; ++j) {
        int p = train_positions[j];
        if (p != -1 && p <= d && p < min) {
          min = p;
        }
      }
      if (min == INT_MAX) {
        cout << "-1" << endl;
      } else {
        cout << (d - min) << endl;
      }
    }
  }
  return 0;
  return 0;
}

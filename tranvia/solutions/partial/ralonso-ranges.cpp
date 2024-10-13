// @ocimatic should-fail=[st2]

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int UNKNOWN = -1;

int main () {
  int l, n, m, e;

  cin >> l >> n >> m >> e;

  vector<int> p_stations(n + 1, -2);
  vector<int> p_trains(m + 1, UNKNOWN);
  vector<unordered_multiset<int>> ranges(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> p_stations[i];
  }

  for (int i = 0; i < m; i++) {
    ranges[0].emplace(-1);
  }

  for (int i = 0; i < e; i++) {
    int t, j, p;

    cin >> t;

    if (t == 1) {
      cin >> j >> p;

      int old_range = lower_bound(p_stations.begin(), p_stations.end(), p_trains[j]) - p_stations.begin() - 1;
      int new_range = lower_bound(p_stations.begin(), p_stations.end(), p) - p_stations.begin() - 1;

      unordered_multiset<int>::iterator to_delete = ranges[old_range].find(p_trains[j]);
      ranges[old_range].erase(to_delete);

      ranges[new_range].emplace(p);

      p_trains[j] = p;
    } else {
      cin >> j;

      // Los trenes que están después de p_stations[j] son equivalentes a posición desconocida para esta búsqueda
      int p_closest = UNKNOWN;

      for (int k = j - 1; k >= 0; k--) {
        if (!ranges[k].empty()) {
          for (auto p: ranges[k]) {
            if (p_closest < p) {
              p_closest = p;
            }
          }
          break;
        }
      }

      if (p_closest == UNKNOWN) {
        cout << -1 << endl;
        continue;
      }
      cout << p_stations[j] - p_closest << endl;
    }
  }
}

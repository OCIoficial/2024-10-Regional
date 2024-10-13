// @ocimatic should-fail=[st2]

#include <iostream>
#include <map>
#include <vector>

using namespace std;

constexpr int UNKNOWN = -1;

int main () {
  int l, n, m, e;

  cin >> l >> n >> m >> e;

  vector<int> p_stations(n + 1);
  vector<int> p_trains(m + 1, UNKNOWN);

  for (int i = 1; i <= n; i++) {
    cin >> p_stations[i];
  }

  for (int i = 0; i < e; i++) {
    int t, j, p;

    cin >> t;      

    if (t == 1) {
      cin >> j >> p;

      p_trains[j] = p;
    } else {
      cin >> j;

      // Los trenes que están después de p_stations[j] son equivalentes a posición desconocida para esta búsqueda
      int p_closest = UNKNOWN;

      for (int k = 1; k <= m; k++) {
        if (p_closest < p_trains[k] && p_trains[k] <= p_stations[j]) {
          p_closest = p_trains[k];
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

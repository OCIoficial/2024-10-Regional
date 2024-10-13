// @ocimatic should-fail=[st2]

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

constexpr int UNKNOWN = -1;

vector<int> p_trains;

bool cmp (int i, int j) {
  return p_trains[i] < p_trains[j];
}

bool cmp2 (int i, int j) {
  return i < p_trains[j];
}

int main () {
  int l, n, m, e;

  cin >> l >> n >> m >> e;

  vector<int> p_stations(n + 1);
  p_trains = vector<int>(m + 1, UNKNOWN);
  vector<int> trains_order(m);

  for (int i = 1; i <= n; i++) {
    cin >> p_stations[i];
  }

  for (int i = 1; i <= m; i++) {
    trains_order[i - 1] = i;
  }

  for (int i = 0; i < e; i++) {
    int t, j, p;

    cin >> t;      

    if (t == 1) {
      cin >> j >> p;

      p_trains[j] = p;

      sort(trains_order.begin(), trains_order.end(), cmp);
    } else {
      cin >> j;

      vector<int>::iterator p_next_train = upper_bound(trains_order.begin(), trains_order.end(), p_stations[j], cmp2);
      int closest_train_idx = p_next_train - trains_order.begin() - 1;
      if (closest_train_idx < 0 || p_trains[trains_order[closest_train_idx]] == -1) {
        cout << -1 << endl;
        continue;
      }
      cout << p_stations[j] - p_trains[trains_order[closest_train_idx]] << endl;
    }
  }
}

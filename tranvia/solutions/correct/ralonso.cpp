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

  map<int, int> train_count;

  for (int i = 1; i <= n; i++) {
    cin >> p_stations[i];
  }

  for (int i = 0; i < e; i++) {
    int t, j, p;

    cin >> t;      

    if (t == 1) {
      cin >> j >> p;

      if (p_trains[j] != UNKNOWN) {
        map<int, int>::iterator p_train = train_count.find(p_trains[j]);

        if (p_train->second > 1) {
          p_train->second--;
        } else {
          train_count.erase(p_train);
        }
      }

      if (p != UNKNOWN) {
        train_count[p]++;
      }

      p_trains[j] = p;
    } else {
      cin >> j;

      map<int, int>::iterator p_next_train = train_count.upper_bound(p_stations[j]);
      if (p_next_train == train_count.begin()) {
        cout << -1 << endl;
        continue;
      }
      cout << p_stations[j] - (--p_next_train)->first << endl;
    }
  }
}

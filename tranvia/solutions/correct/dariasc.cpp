#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...) 0
#endif

template <typename T> using vec = vector<T>;
using ll = long long;
using ld = long double;
istream &in = cin;
ostream &out = cout;
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  in.tie(0);
  ios_base::sync_with_stdio(0);

  int l, n, m, e;
  in >> l >> n >> m >> e;

  vec<int> d(n);
  for (int i = 0; i < n; i++) {
    in >> d[i];
  }

  vec<int> pos(m);
  set<pair<int, int>> S;
  while (e--) {
    int t;
    in >> t;
    if (t == 1) {
      int j, p;
      in >> j >> p;
      j--;
      S.erase({pos[j], j});
      if (p != -1) {
        S.insert({p, j});
      }
      pos[j] = p;
    } else {
      int i;
      in >> i;
      i--;
      auto it = S.upper_bound({d[i], 1e9});
      if (it == S.begin()) {
        out << -1 << "\n";
        continue;
      }
      it--;
      out << d[i] - (*it).first << "\n";
    }
  }

  return 0;
}

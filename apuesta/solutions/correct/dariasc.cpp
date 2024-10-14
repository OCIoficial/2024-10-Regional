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

  int n;
  in >> n;
  vec<int> a(n);
  for (int i = 0; i < n; i++) {
    in >> a[i];
  }

  int P = 0;
  ll ans = 0;
  int o = 0, u = 0;
  unordered_map<int, int> O, U;
  for (int i = 0; i < n+1; i++) {
    ans += u;
    if (i < n) {
      if (a[i] > 0) {
        // move P from over to under
        o -= O[P];
        u += O[P];
        U[P] = O[P];
        O[P] = 0;
        // add P to under
        U[P]++;
        u++;
      } else if (a[i] < 0) {
        // move P-1 from under to over
        o += U[P-1];
        u -= U[P-1];
        O[P-1] = U[P-1];
        U[P-1] = 0;
        // add P to over
        O[P]++;
        o++;
      }
      P += a[i];
    }
  }
  out << ans << "\n";

  return 0;
}

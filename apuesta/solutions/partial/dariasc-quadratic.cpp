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

  vec<int> p(n+1);
  for (int i = 0; i < n; i++) {
    p[i+1] = a[i] + p[i];
  }

  ll ans = 0;
  map<int, int> M;
  M[0] = 1;
  for (int i = 0; i < n; i++) {
    for (auto [k, v] : M) {
      if (k < p[i+1]) {
        ans += v;
      }
    }
    M[p[i+1]]++;
  }
  out << ans << "\n";

  return 0;
}

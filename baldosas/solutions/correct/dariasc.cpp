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

  ll n, m;
  in >> n >> m;

  ll b_row0 = n/2;
  ll b_row1 = (n+1)/2;

  ll b = b_row0 * ((m+1)/2) + b_row1 * (m/2);
  ll w = n*m - b;

  out << w << " " << b << "\n";
  return 0;
}

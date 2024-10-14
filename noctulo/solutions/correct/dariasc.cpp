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

  string a, b;
  in >> a >> b;
  int i = 0;
  while (i < 35) {
    if (a[i % sz(a)] == b[i % sz(b)]) {
      out << i << "\n";
      return 0;
    }
    i++;
  }
  out << "No nos vemos nunca\n";

  return 0;
}

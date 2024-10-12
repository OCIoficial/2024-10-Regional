#include <iostream>
using namespace std;

int64_t ceil2(int64_t x) { return (x + 1) / 2; }
int64_t floor2(int64_t x) { return x / 2; }

int64_t white(int64_t n, int64_t m) {
  return ceil2(n) * ceil2(m) + floor2(n) * floor2(m);
}

int64_t black(int64_t n, int64_t m) {
  return ceil2(n) * floor2(m) + floor2(n) * ceil2(m);
}

int main() {
  int64_t n, m;
  cin >> n >> m;

  cout << white(n, m) << " " << black(n, m) << endl;

  return 0;
}

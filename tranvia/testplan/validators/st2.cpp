#include <vector>

#include "testlib.h"

using namespace std;

constexpr int MAX_L = 1e9;
constexpr int MAX_N = 1e5;
constexpr int MAX_M = 1e5;
constexpr int MAX_E = 4 * 1e5;

int main() {
  registerValidation();
  int l = inf.readInt(1, MAX_L, "l");
  inf.readSpace();
  int n = inf.readInt(1, MAX_N, "n");
  inf.readSpace();
  int m = inf.readInt(1, MAX_M, "m");
  inf.readSpace();
  int e = inf.readInt(1, MAX_E, "e");
  inf.readEoln();

  vector<int> p_n(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    p_n[i] = inf.readInt(0, l, "n_" + to_string(i));
    ensuref(p_n[i - 1] < p_n[i], "Stations %d, %d are not in strictly increasing order.", i - 1, i);
    if (i != n) {
      inf.readSpace();
    }
  }
  inf.readEoln();

  for (int i = 1; i <= e; i++) {
    int t = inf.readInt(1, 2, "e_" + to_string(i) + ": t");
    inf.readSpace();

    if (t == 1) {
      inf.readInt(1, m, "e_" + to_string(i) + ": j");
      inf.readSpace();
      inf.readInt(-1, l, "e_" + to_string(i) + ": p");
    } else {
      inf.readInt(1, n, "e_" + to_string(i) + ": i");
    }
    inf.readEoln();
  }

  inf.readEof();
}

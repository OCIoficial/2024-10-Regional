#include "testlib.h"

int main() {
  registerValidation();
  int n = inf.readInt(1, 100, "n");
  inf.readEoln();
  for (int i = 0; i < n; ++i) {
    if (i > 0) inf.readSpace();
    int t = inf.readInt();
    ensuref(t == -1 || t == 1, "la moneda debe ser cara o sello");
  }
  inf.readEoln();
  inf.readEof();
}

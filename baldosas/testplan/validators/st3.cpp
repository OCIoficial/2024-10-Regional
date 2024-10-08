#include "testlib.h"

int main() {
  registerValidation();
  int n = inf.readInt(1, 1e9, "n");
  ensuref(n%2 == 0, "n debe ser par");
  inf.readSpace();
  int m = inf.readInt(1, 1e9, "m");
  ensuref(m%2 == 0, "m debe ser par");
  inf.readEoln();
  inf.readEof();
}

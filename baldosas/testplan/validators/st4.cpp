#include "testlib.h"

const long long UPPER = 1'000'000'000'000'000'000;

int main() {
  registerValidation();
  int n = inf.readLong(1LL, UPPER, "n");
  inf.readSpace();
  int m = inf.readLong(1LL, UPPER, "m");
  ensuref(n <= UPPER/m, "n*m debe ser menor o igual a 1e18");
  inf.readEoln();
  inf.readEof();
}

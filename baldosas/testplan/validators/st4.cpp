#include "testlib.h"

const long long UPPER = 1'000'000'000'000'000'000;

int main() {
  registerValidation();
  long long n = inf.readLong(1LL, UPPER, "n");
  inf.readSpace();
  long long m = inf.readLong(1LL, UPPER, "m");
  ensuref(n <= UPPER/m, "n*m debe ser menor o igual a 1e18");
  inf.readEoln();
  inf.readEof();
}

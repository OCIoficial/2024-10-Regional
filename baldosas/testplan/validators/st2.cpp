#include "testlib.h"

const long long UPPER = 1'000'000'000'000'000'000;

int main() {
  registerValidation();
  inf.readInt(1, 1, "n");
  inf.readSpace();
  inf.readLong(1LL, UPPER, "m");
  inf.readEoln();
  inf.readEof();
}

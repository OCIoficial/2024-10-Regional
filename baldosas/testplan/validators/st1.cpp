#include "testlib.h"

int main() {
  registerValidation();
  inf.readInt(1, 1e3, "n");
  inf.readSpace();
  inf.readInt(1, 1e3, "m");
  inf.readEoln();
  inf.readEof();
}
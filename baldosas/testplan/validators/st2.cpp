#include "testlib.h"

int main() {
  registerValidation();
  inf.readInt(1, 1, "n");
  inf.readSpace();
  inf.readInt(1, 1e9, "m");
  inf.readEoln();
  inf.readEof();
}

#include "testlib.h"

int main() {
  registerValidation();
  std::string ricardo = inf.readLine("[DN]{7}");
  std::string noctulo = inf.readLine("[DN]{5}");
  inf.readEof();
}

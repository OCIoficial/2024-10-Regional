#include "testlib.h"

int main() {
  registerValidation();
  std::string ricardo = inf.readLine("[DN]{7}");
  std::string noctulo = inf.readLine("[DN]{5}");
  inf.readEof();

  bool b = false;
  for (int i = 0; i < 5; ++i) {
    if (ricardo[i] == noctulo[i]) {
      b = true;
    }
  }
  ensuref(b, "no se encuentran en la primera semana");
}

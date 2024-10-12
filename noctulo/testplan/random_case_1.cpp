#include <cassert>
#include <iostream>
#include <random>

bool check_answer(const std::vector<int> &fw, const std::vector<int> &sw,
                  int d) {
  for (int i = 0; i < 35; ++i) {
    if (fw[i % 7] == sw[i % 5]) {
      return i == d;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  //  The argument in position 1 is the hidden seed.
  std::hash<std::string> hasher;
  std::mt19937 gen(hasher(argv[1]));

  const int DAY = std::atoi(argv[2]);
  assert(0 <= DAY && DAY <= 4);

  std::vector<int> fw(7, -1);
  std::vector<int> sw(5, -1);

  std::uniform_int_distribution<int> random_day(0, 1);
  for (int i = 0; i < 7; i++) {
    fw[i] = random_day(gen);
    if (i < DAY) {
      // Forzar que antes de `DAY` no se encuentren
      sw[i] = !fw[i];
    } else if (i == DAY) {
      // Forzar que en `DAY` si se encuentren
      sw[i] = fw[i];
    } else if (i < 5) {
      // El resto no importa
      sw[i] = random_day(gen);
    }
  }

  assert(check_answer(fw, sw, DAY));

  for (int i = 0; i < 7; i++) {
    if (fw[i]) {
      std::cout << "D";
    } else {
      std::cout << "N";
    }
  }
  std::cout << std::endl;
  for (int i = 0; i < 5; i++) {
    if (sw[i]) {
      std::cout << "D";
    } else {
      std::cout << "N";
    }
  }
  std::cout << std::endl;

  return 0;
}

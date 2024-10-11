#include <cassert>
#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
  //  The argument in position 1 is the hidden seed.
  std::hash<std::string> hasher;
  std::mt19937 gen(hasher(argv[1]));

  const int DAY = std::atoi(argv[2]);
  assert(5 <= DAY && DAY <= 10);

  std::vector<int> fw(7, -1);
  std::vector<int> sw(5, -1);
  std::uniform_int_distribution<int> random_day(0, 1);
  switch (DAY){
    case 5:
      for (int i=0;i<7;i++){
        if (i < 5){
          fw[i] = random_day(gen);
          sw[i] = !fw[i];
        }
        if (i == 5) fw[i] = sw[0];
        if (i == 6) fw[i] = random_day(gen);
      }
      break;
    case 6:
      for (int i=0;i<7;i++){
        if (i < 5){
          fw[i] = random_day(gen);
          sw[i] = !fw[i];
        }
        if (i == 5) fw[i] = fw[0];
        if (i == 6) fw[i] = sw[1];
      }
      break;
    case 7:
      for (int i=0;i<7;i++){
        if (i == 2){
          sw[i] = fw[0];
          fw[i] = !sw[i];
        } else if (i < 5){
          fw[i] = random_day(gen);
          sw[i] = !fw[i];
        }
        if (i == 5) fw[i] = fw[0];
        if (i == 6) fw[i] = fw[1];
      }
      break;
    case 8:
      fw[0] = fw[5] = fw[2] = random_day(gen);
      sw[0] = sw[2] = !fw[0];
      fw[1] = fw[6] = sw[3] = random_day(gen);
      sw[1] = fw[3] = !fw[1];
      fw[4] = random_day(gen);
      sw[4] = !fw[4];
      break;
    case 9:
      fw[0] = fw[5] = fw[2] = sw[4] = random_day(gen);
      sw[0] = sw[2] = fw[4] = !fw[0];
      fw[1] = fw[6] = fw[3] = random_day(gen);
      sw[1] = sw[3] = !fw[1];
      break;
    case 10:
      fw[0] = fw[5] = fw[2] = fw[4] = sw[1] = sw[3] = random_day(gen);
      sw[0] = sw[2] = sw[4] = fw[1] = fw[6] = fw[3] = !fw[0];
      break;
  }

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

// This script generates random test cases for the sample task. It takes a
// minimum and maximum value and prints two random numbers in that range.
// See the comment in testplan.txt for further details.

#include <cassert>
#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
  //  The argument in position 1 is the hidden seed.
  std::hash<std::string> hasher;
  std::mt19937 gen(hasher(argv[1]));


  const int CASE = std::atoi(argv[2]);
  assert(CASE == 1 || CASE == 2);

  std::vector<int> fw(7,-1);
  std::vector<int> sw(5,-1);

  if (CASE == 1){
    std::uniform_int_distribution<int> dist(0,4);
    int day = dist(gen);
    std::uniform_int_distribution<int> random_day(0,1);
    for (int i=0;i<7;i++){
      fw[i] = random_day(gen);
      if (i < day){
        sw[i] = !fw[i];
      } else if (i == day){
        sw[i] = fw[i];
      } else if (i <5){
        sw[i] = random_day(gen);
      }
    }
  } else if (CASE == 2){
    std::uniform_int_distribution<int> dist(0,4);
    int day = dist(gen) + 5;
    std::uniform_int_distribution<int> random_day(0,1);
    fw[day%7] = random_day(gen);
    sw[day%5] = fw[day%7];
    for (int i=0;i<7;i++){
      if (i < 5){
        if (fw[i] != -1){
          sw[i] = !fw[i];
        } else if (sw[i] != -1){
          fw[i] = !sw[i];
        } else {
          fw[i] = random_day(gen);
          sw[i] = !fw[i];
        }
      }
      if (fw[i] == -1) fw[i] = random_day(gen);
    }
  }

  for (int i=0;i<7;i++){
    if (fw[i]) std::cout<<"D";
    else std::cout<<"N";
  }
  std::cout<<std::endl;
  for (int i=0;i<5;i++){
    if (sw[i]) std::cout<<"D";
    else std::cout<<"N";
  }
  std::cout<<std::endl;

  return 0;
}

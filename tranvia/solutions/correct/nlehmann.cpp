#include <climits>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int find_closest_train_pos(const set<pair<int, int>>& sorted_trains, int d) {
  // Esto retorna el primer tren cuya posición es estrictamente mayor
  auto it = sorted_trains.upper_bound({d, INT_MAX});

  // Si no hay mas trenes hacia atras, entonces no hay ningun tren que se
  // aproxime a la estación
  if (it == sorted_trains.cbegin()) {
    return -1;
  }

  // En caso contrario el tren anterior es el primero cuya posición es menor o
  // igual asi que retornamos su posición
  it--;
  return it->first;
}

int main() {
  int L, N, M, E;

  cin >> L >> N >> M >> E;

  // Distancia de cada estación
  vector<int> station_distance(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> station_distance[i];
  }

  // Posición de cada tren
  vector<int> train_positions(M + 1, -1);

  // Conjunto de pares (p, j) donde p es la posición del tren y j el numero del
  // tren
  set<pair<int, int>> sorted_trains;

  for (int i = 0; i < E; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int j, p;
      cin >> j >> p;

      sorted_trains.erase({train_positions[j], j});
      train_positions[j] = p;

      if (p == -1) {
        continue;
      }

      sorted_trains.emplace(p, j);
    } else {
      int i;
      cin >> i;

      int d = station_distance[i];
      int p = find_closest_train_pos(sorted_trains, d);
      if (p == -1) {
        cout << "-1" << endl;
      } else {
        int time = (d - p);
        cout << time << endl;
      }
    }
  }
  return 0;
}

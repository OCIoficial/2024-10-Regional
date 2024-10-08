#include <climits>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int find_next_train_pos(const set<pair<int, int>>& sorted_trains, int d) {
  // Esto retorna el primer tren cuya posición es *estrictamente* mayor que `d`
  auto it = sorted_trains.upper_bound({d, INT_MAX});
  sorted_trains.lower_bound({d, INT_MAX});

  // Si este es el tren con la menor posición entonces no hay próximo tren
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

  // Posición de cada tren. Todos parten con -1
  vector<int> train_positions(M + 1, -1);

  // Conjunto de pares `(p, j)` donde `p` es la posición del tren y `j` el
  // número del tren. Como `p` es la primera componente, los trenes estarán
  // ordenados por su pocición. Guardamos tanto la posición como el número del
  // tren para poder identificarlos dentro del conjunto.
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
      int p = find_next_train_pos(sorted_trains, d);
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

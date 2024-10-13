import random
import sys


random.seed(sys.argv[1])

N = int(sys.argv[2])
direction = sys.argv[3]

L = random.randint(100_000_000, 1_000_000_000)

print(L, N, N, 4 * N)

# Poner las estaciones en posiciones aleatorias
D = sorted(random.sample(range(10, L, 2), N))
print(" ".join(str(d) for d in D))

# Poner un tren entre cada par de estaciones
for j in range(N):
    p = random.randint(D[j - 1] + 1 if j > 0 else 0, D[j] - 1)
    print(1, j + 1, p)

# Preguntar dos veces por cada estación intercalado con eliminar un tren
stations = list(range(1, N + 1))
random.shuffle(stations)
if direction == "reverse":
    stations.reverse()
for i in stations:
    print(2, i)
    print(1, i, -1)
    print(2, i)

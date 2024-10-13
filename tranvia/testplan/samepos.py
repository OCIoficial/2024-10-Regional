import random
import sys

random.seed(sys.argv[1])

N = int(sys.argv[2])
M = int(sys.argv[3])
G = int(sys.argv[4])
L = random.randint(100_000_000, 1_000_000_000)

print(L, N, M, M // G + N)

# Poner las estaciones en posiciones aleatorias
D = sorted(random.sample(range(0, L + 1), N))
print(*D)

# Dividir los trenes grupos de tamaño G y poner todos los trenes del mismo grupo
# en la misma posición
P = sorted(random.sample(range(0, L), M // G))
j = 1
for k in range(M // G):
    for _ in range(G):
        print(1, j, P[k])
        j += 1

# Preguntar por cada una de las estaciones
stations = list(range(1, N + 1))
random.shuffle(stations)
for i in stations:
    print(2, i)

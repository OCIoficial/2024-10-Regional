# La cantidad de trenes y estaciones es la misma e igual a N
# Primero genera N consultas de tipo 1 poniendo los trenes en distintas aleatorias,
# luego pregunta por el próximo tren para cada una de las N estaciones.
import random
import sys

random.seed(sys.argv[1])

N = int(sys.argv[2])
direction = sys.argv[3]

L = random.randint(100_000_000, 1_000_000_000)

assert 2 * N <= 100000

print(L, N, N, 2 * N)

# Poner las estaciones en posiciones aleatorias
D = sorted(random.sample(range(0, L + 1), N))
print(" ".join(str(d) for d in D))

# Poner los trenes en posiciones aleatorias
P = sorted(random.sample(range(0, L + 1), N))
for j, p in enumerate(P, start=1):
    print(1, j, p)

# Preguntar por cada una de las estaciones
stations = list(range(1, N + 1))
random.shuffle(stations)
if direction == "reverse":
    stations.reverse()
for i in stations:
    print(2, i)

import random
import sys

random.seed(sys.argv[1])

N = int(sys.argv[2])
M = int(sys.argv[3])
E = int(sys.argv[4])

L = random.randint(100_000_000, 1_000_000_000)

print(L, N, M, E)

# Poner las estaciones en posiciones aleatorias
D = sorted(random.sample(range(0, L + 1), N))
print(" ".join(str(d) for d in D))

# Generar consultas aleatorias
for _ in range(E):
    t = random.randint(1, 2)
    print(t, end=" ")
    if t == 1:
        j = random.randint(1, M)
        p = random.randint(-1, L)
        print(j, p)
    else:
        i = random.randint(1, N)
        print(i)

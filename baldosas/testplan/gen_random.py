import random
import sys

# args: [random gen seed] [n_max] [m_max]
random.seed(sys.argv[1])
n_max, m_max = int(sys.argv[2]), int(sys.argv[3])

n = random.randint(1, n_max)
m = random.randint(1, m_max)

print(n, m)

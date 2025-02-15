# This script generates random test cases for the sample task. It takes a
# minimum and maximum value and prints two random numbers in that range.
# See the comment in testplan.txt for further details.

import random
import sys

# The argument in position 1 is the hidden seed.
random.seed(sys.argv[1])

# The max is in position 2
MAX = int(sys.argv[2])


n = random.randint(1, MAX)
choices = [-1,1]
coins = []
for i in range(n):
    coins += (random.sample(choices,1))


print(n)
print(' '.join(map(str,coins)))

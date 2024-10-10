# This script generates random test cases for the sample task. It takes a
# minimum and maximum value and prints two random numbers in that range.
# See the comment in testplan.txt for further details.

import sys

N = int(sys.argv[2])


coins = []
for i in range(N):
    if (i % 2):
        coins.append(-1)
    else:
        coins.append(1)


print(N)
print(' '.join(map(str,coins)))

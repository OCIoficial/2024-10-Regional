# @ocimatic should-fail=[st2,st3,st4]

n, m = [int(x) for x in input().split()]

white = 0
black = 0
for i in range(n):
    for j in range(m):
        if (i+j)%2 == 0:
            white += 1
        else:
            black += 1
print(white, black)

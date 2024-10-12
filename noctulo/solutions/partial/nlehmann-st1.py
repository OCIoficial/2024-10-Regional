# @ocimatic should-fail=[st2]

ricardo = input().rstrip()
noctulo = input().rstrip()

for i in range(0, 5):
    if ricardo[i] == noctulo[i]:
        print(i)
        break
else:
    print("No nos vemos nunca")

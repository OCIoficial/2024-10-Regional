ricardo = input().rstrip()
noctulo = input().rstrip()

for i in range(0, 35):
    if ricardo[i % 7] == noctulo[i % 5]:
        print(i)
        break
else:
    print("No nos vemos nunca")

n = input()
cont = 0
for i in range(len(n)):
    if int(n[i]) == 0:
        continue
    elif int(n) % int(n[i]) == 0:
        cont += 1
print(cont)
n = int(input())
s = input()

a = 0
c = 0

for i in range(n):
    if s[i] == 'a':
        c = c+1
    else:
        if c > 1:
            a = a+c
        c = 0
    if i == n-1 and s[i] == 'a' and c > 1:
        a = a+c

print(a)

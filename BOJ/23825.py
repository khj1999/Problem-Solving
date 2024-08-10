n, m = map(int, input().split())
n /= 2
m /= 2
print((int(m if n > m else n)))
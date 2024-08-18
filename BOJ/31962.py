n, x = map(int, input().split())
max_bus =  0

for _ in range(n):
    s, t = map(int, input().split())
    if s + t <= x:
        if s > max_bus:
            max_bus = s

if max_bus == 0:
    max_bus = -1;

print(max_bus)
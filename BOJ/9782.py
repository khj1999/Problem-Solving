import statistics
# 나중에
while True:
    n = int(input())
    if n == 0:
        break
    ls = [int(input()) for _ in range(n)]
    print(statistics.median(ls))
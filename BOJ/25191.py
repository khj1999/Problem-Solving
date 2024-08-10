n = int(input())
a, b = map(int, input().split())
sum = b;
sum += a / 2
print(int(n if sum > n else sum))
h = int(input())
w = int(input())

tmp = w if h > w else h
print(int(tmp * 100 / 2))
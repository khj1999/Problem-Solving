n = int(input())

data = [input() for _ in range(n)]
pt = data[0]
solve = list(data[0])

for string in data:
    for i in range(len(string)):
        if pt[i] != string[i]:
            solve[i] = '?'
    
print(''.join(solve))
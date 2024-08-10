register = {
    "black": ['0', 1],
    "brown": ['1', 10],
    "red": ['2', 100],
    "orange": ['3', 1000],
    "yellow": ['4', 10000],
    "green": ['5', 100000],
    "blue": ['6', 1000000],
    "violet": ['7', 10000000],
    "grey": ['8', 100000000],
    "white": ['9', 1000000000]
}

color = [input() for _ in range(3)]

ans = ''
for i in range(3):
    if i == 0 or i == 1:
        ans += register[color[i]][0]
    else:
        ans = int(ans)
        ans *= register[color[i]][1]

print(ans)
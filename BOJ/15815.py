num = []
ans = 0

string = input()
for cur in string:
    if cur in ['+', '-', '*', '/']:
        b = (int)(num.pop())
        a = (int)(num.pop())
        if cur == '+':
            ans = a + b
        elif cur == '-':
            ans = a - b
        elif cur == '*':
            ans = a * b
        elif cur == '/':
            ans = a // b 
        num.append(ans)
    else:
        num.append(cur)
            
print(ans)
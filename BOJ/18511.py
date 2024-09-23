import sys
from itertools import permutations

input = sys.stdin.readline

def solve(n: int, ls: list) -> int:
    str_n = str(n)
    length = len(str_n)
    tmp = []

    # 가능한 모든 자리수의 조합을 생성
    for i in range(1, length + 1):
        for perm in permutations(ls, i):
            # 조합을 정수로 변환
            num = int(''.join(perm))
            # n보다 작거나 같은지 확인
            if num <= n:
                tmp.append(num)

    # 결과 리스트에서 최대값을 반환
    return max(tmp)

# 입력 처리
n, k = map(int, input().split())
ls = list(input().split())

# 가장 큰 숫자 찾기
print(solve(n, ls))

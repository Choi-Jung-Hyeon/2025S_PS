import sys
input = sys.stdin.readline

N, M = map(int, input().split())
sequence = []
results = []

def backtrack(start):
    if len(sequence) == M:
        results.append(" ".join(map(str, sequence)))
        return
    for num in range(start, N + 1):
        sequence.append(num)
        backtrack(num)  # 중복 허용 & 비내림차순을 위해 현재 수(num)부터 시작
        sequence.pop()

backtrack(1)
sys.stdout.write("\n".join(results))
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
sequence = []
results = []

def backtrack(start):
    if len(sequence) == M:
        results.append(" ".join(map(str, sequence)))
        return
    for i in range(start, N + 1):
        sequence.append(i)
        backtrack(i + 1)
        sequence.pop()

backtrack(1)
sys.stdout.write("\n".join(results))
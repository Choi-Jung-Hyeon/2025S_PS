import sys
input = sys.stdin.readline

N, M = map(int, input().split())
sequence = []
results = []

def backtrack():
    if len(sequence) == M:
        results.append(" ".join(map(str, sequence)))
        return
    
    for num in range(1, N + 1):
        sequence.append(num)
        backtrack()
        sequence.pop()

backtrack()
sys.stdout.write("\n".join(results))
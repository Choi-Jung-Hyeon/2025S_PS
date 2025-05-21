import sys
input = sys.stdin.readline

N, M = map(int, input().split())
sequence = []
results = []
visited = [False] * (N + 1)

def backtrack():
    if len(sequence) == M:
        results.append(" ".join(map(str, sequence)))
        return

    for num in range(1, N + 1):
        if not visited[num]:
            visited[num] = True
            sequence.append(num)
            backtrack()
            sequence.pop()
            visited[num] = False
            
backtrack()
sys.stdout.write("\n".join(results))
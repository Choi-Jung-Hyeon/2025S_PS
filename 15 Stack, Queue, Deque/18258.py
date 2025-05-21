import sys
from collections import deque

data = sys.stdin.read().split()
n = int(data[0])
queue = deque()
results = []
pos = 1

for _ in range(n):
    cmd = data[pos]
    pos += 1
    if cmd == "push":
        queue.append(int(data[pos]))
        pos += 1
    elif cmd == "pop":
        results.append(str(queue.popleft()) if queue else "-1")
    elif cmd == "size":
        results.append(str(len(queue)))
    elif cmd == "empty":
        results.append("0" if queue else "1")
    elif cmd == "front":
        results.append(str(queue[0]) if queue else "-1")
    elif cmd == "back":
        results.append(str(queue[-1]) if queue else "-1")

sys.stdout.write("\n".join(results))
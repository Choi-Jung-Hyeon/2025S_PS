import sys
from collections import deque

data = sys.stdin.read().split()
n = int(data[0])
dq = deque()
output = []
pos = 1

for _ in range(n):
    cmd = data[pos]
    pos += 1
    if cmd == "1":         # "1 X": 정수 X를 덱의 앞에 넣는다.
        x = int(data[pos])
        pos += 1
        dq.appendleft(x)
    elif cmd == "2":       # "2 X": 정수 X를 덱의 뒤에 넣는다.
        x = int(data[pos])
        pos += 1
        dq.append(x)
    elif cmd == "3":       # "3": 덱에 있으면 맨 앞 정수를 빼고 출력, 없으면 -1
        output.append(str(dq.popleft()) if dq else "-1")
    elif cmd == "4":       # "4": 덱에 있으면 맨 뒤 정수를 빼고 출력, 없으면 -1
        output.append(str(dq.pop()) if dq else "-1")
    elif cmd == "5":       # "5": 덱에 들어있는 정수의 개수를 출력
        output.append(str(len(dq)))
    elif cmd == "6":       # "6": 덱이 비어있으면 1, 아니면 0을 출력
        output.append("1" if not dq else "0")
    elif cmd == "7":       # "7": 덱에 있으면 맨 앞 정수를 출력, 없으면 -1
        output.append(str(dq[0]) if dq else "-1")
    elif cmd == "8":       # "8": 덱에 있으면 맨 뒤 정수를 출력, 없으면 -1
        output.append(str(dq[-1]) if dq else "-1")

sys.stdout.write("\n".join(output))
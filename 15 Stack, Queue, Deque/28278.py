import sys

# 전체 입력을 한 번에 읽고, 공백 기준으로 토큰으로 분리합니다.
data = sys.stdin.read().split()
N = int(data[0])
stack = []
results = []
pos = 1

# 각 명령어를 토큰 단위로 처리합니다.
for _ in range(N):
    command = data[pos]
    pos += 1
    if command == "1":  # 명령 "1 X": 스택에 정수 X를 추가
        stack.append(int(data[pos]))
        pos += 1
    elif command == "2":  # 명령 "2": 스택에서 최상단 값을 pop하고 출력, 없으면 -1
        if stack:
            results.append(stack.pop())
        else:
            results.append(-1)
    elif command == "3":  # 명령 "3": 스택의 크기를 출력
        results.append(len(stack))
    elif command == "4":  # 명령 "4": 스택이 비어있으면 1, 아니면 0을 출력
        results.append(0 if stack else 1)
    elif command == "5":  # 명령 "5": 스택의 최상단 값을 출력, 없으면 -1
        results.append(stack[-1] if stack else -1)

# 결과를 한 번에 출력합니다.
sys.stdout.write("\n".join(map(str, results)))
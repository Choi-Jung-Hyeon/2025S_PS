n = int(input())
company = set()
for _ in range(n):
    name, action = input().split()
    if action == "enter":
        company.add(name)
    else:
        company.discard(name)

for name in sorted(company, reverse=True):
    print(name)
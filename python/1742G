def solve():
    N = int(input())
    array = list(map(int, input().split()))
    array.sort()
    array.reverse()

    value = array[0]

    b = []
    b.append(array[0])

    visited = [False] * N
    visited[0] = True

    for i in range(33):
        mx = value
        for i in range(N):
            if not visited[i]:
                new_value = (value | array[i])
                mx = max(mx, new_value)
        for i in range(N):
            if not visited[i]:
                new_value = (value | array[i])
                if new_value == mx:
                    b.append(array[i])
                    visited[i] = True
                    value = new_value
                    break

    for i in range(N):
        if not visited[i]:
            b.append(array[i])

    print(*b)

for _ in range(int(input())):
    solve()

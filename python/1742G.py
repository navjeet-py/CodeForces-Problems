from math import gcd


def solve():
    a, b, c, d = map(int, input().split())
    alpha = a * b
    for x in range(a + 1, c + 1):
        g = gcd(x, alpha)
        p = alpha // g
        k = b // p
        if p * (k + 1) <= d:
            print(x, p * k + p)
            return

    print(-1, -1)

for _ in range(int(input())):
    solve()

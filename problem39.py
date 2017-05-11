from math import sqrt
squares = {i**2: i for i in range(1001)}
sols = {}
for a in range(1, 334):
    b = a
    while b <= (1000-a)/2.:
        sq = a**2 + b**2
        if sq in squares:
            c = squares[sq]
            p = a+b+c
            sols.setdefault(p, [])
            sols[p].append((a, b, c))
        # if a + b + sqrt(sq) > 1000:
        #     break
        b += 1

s = sorted(sols.keys(), key=lambda k: len(sols[k]), reverse=True)
print s[0]
print sols[s[0]]
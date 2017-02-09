def gcd(a, b):
    if a == b:
        return a
    if a < b:
        return gcd(a, b-a)
    else:
        return gcd(a-b, b)

def reduce(a, b):
    d = gcd(a, b)
    return a/d, b/d

def check(i, j, a, b, frac):
    if reduce(i, j) == reduce(a, b):
        x, y = reduce(a, b)
        frac = frac[0]*x, frac[1]*y
    return frac


if __name__ == "__main__":
    frac = 1, 1
    for i in range(10, 100):
        for j in range(i+1, 100):
            a1, a2 = i/10, i%10
            b1, b2 = j/10, j%10
            if i%10==0 or j%10==0:
                continue
            if a1 == b1:
                frac = check(i, j, a2, b2, frac)
            elif a1 == b2:
                frac = check(i, j, a2, b1, frac)
            elif a2 == b1:
                frac = check(i, j, a1, b2, frac)
            elif a2 == b2:
                frac = check(i, j, a1, b1, frac)
    print frac
    print reduce(*frac)
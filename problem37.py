from math import sqrt


def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    for k in range(2, int(sqrt(n))+1):
        if n % k == 0:
            return False
    return True


def is_right_admissible(n):
    k = 1
    while 10**k <= n:
        r = n % (10**k)
        if not is_prime(r):
            return False
        k += 1
    return is_prime(n)


starts = [23, 29, 31, 37, 53, 59, 71, 73, 79]
ends = [13, 17, 37, 73, 97]
l = []
for k in starts:
    tmp = [k]
    while len(tmp) > 0:
        n = tmp.pop()
        if is_right_admissible(n):
            if n not in l:
                l.append(n)
        # for e in ends:
            # if is_right_admissible(n*100+e):
            #     l.append(n*100+e)
        for i in [1, 3, 7, 9]:
            if is_prime(n*10+i):
                tmp.insert(0, n*10+i)
print l, len(l)
print sum(l)

import sets
import math
import copy
primes = {}

def get_digits(n):
    out = []
    while n > 0:
        out.insert(0, n%10)
        n /= 10
    return out

def is_prime(n):
    global primes
    if n in primes:
        return primes[n]
    if n <= 1:
        primes[n] = False
        return False
    for k in range(2, int(math.sqrt(n))+1):
        if n%k == 0:
            primes[n] = False
            return False
    primes[n] = True
    return True

def find_permutations(l):
    n = len(l)
    if n<=1:
        return [copy.deepcopy(l)]
    b = l.pop()
    out = []
    perms = find_permutations(l)
    for perm in perms:
        for k in range(n):
            l2 = copy.deepcopy(perm)
            l2.insert(k, b)
            out.append(l2)
    return out

def make_int(l):
    n = 0
    for i in l:
        n*=10
        n+=i
    return n

def rotate(l, n):
    return l[n:] + l[:n]

if __name__ == "__main__":
    l = [2]
    for k in range(2, 1000000):
        # print k
        if k in l:
            continue
        if is_prime(k):
            digits = get_digits(k)
            if 2 in digits or 4 in digits or 6 in digits or 8 in digits:
                continue
            f = True
            for r in range(len(digits)):
                digits = rotate(digits, 1)
                i = make_int(digits)
                if not is_prime(i):
                    f = False
                    break
            if f:
                l.append(k)
    print l
    print len(l)
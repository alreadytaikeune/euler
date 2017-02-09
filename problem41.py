import math
import copy

def is_prime(n):
    if n == 0 or n == 1:
        return False
    for k in range(2, int(math.sqrt(n))):
        if n%k == 0:
            return False
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

def replace(l, k, n, up=-1):
    up = len(l) if up == -1 else up
    for i in range(up):
        if l[i] == k:
            l[i] = n


def list_potential_pandigitals(n):
    out = []
    perms = find_permutations(range(2, n, 1))
    for perm in perms:
        prev = 1
        perm += [1]
        out.append(perm)
        for k in range(3, n, 2):
            if k%5 == 0:
                continue
            ll = copy.deepcopy(perm)
            replace(ll, k, prev, len(ll)-1)
            ll[-1] = k
            out.append(ll)
            prev = k
    return out
        
def make_int(l):
    n = 0
    for i in l:
        n*=10
        n+=i
    return n

if __name__ == "__main__":
    pans = []
    for l in list_potential_pandigitals(5):
        if is_prime(make_int(l)):
            pans.append(make_int(l))
    for l in list_potential_pandigitals(8):
        if is_prime(make_int(l)):
            pans.append(make_int(l))
    print max(pans)
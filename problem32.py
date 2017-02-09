import copy

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

if __name__ == "__main__":
    l = find_permutations(range(1, 10, 1))
    print len(l)
    d = {}
    for perm in l:
        for i in range(1, 3, 1):
            for j in range(1, 7-i, 1):
                a = make_int(perm[0:i])
                b = make_int(perm[i:i+j])
                c = make_int(perm[i+j:])
                if a*b == c:
                    print a, b, c
                    d[c] = 1
    print d
    print sum(d.keys())
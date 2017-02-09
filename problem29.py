import math 
primes = []

dividers = {}

def is_prime(n):
    if n <= 1:
        return False
    for k in range(2, int(math.sqrt(n))+1):
        if n%k == 0:
            return False
    return True

def merge_dividers(div1, div2):
    for k, v in div2.iteritems():
        if not k in div1:
            div1[k] = v
        else:
            div1[k] += v

def list_dividers(n):
    if n in dividers:
        return dividers[n]
    if n == 1:
        return {1:1}
    if is_prime(n):
        dividers[n] = {n:1}
        return dividers[n]
    divs = {}
    for k in range(2, n):
        if n%k == 0:
            merge_dividers(divs, list_dividers(k))
            merge_dividers(divs, list_dividers(n/k))
            break
    dividers[n] = divs
    return divs

def is_power_of(divs1, divs2, n):
    if len(divs1) != len(divs2):
        return False
    keys1 = sorted(divs1)
    keys2 = sorted(divs2)
    e = -1
    for i in range(len(keys1)):
        if keys1[i] != keys2[i]:
            return False
        if divs1[keys1[i]] > divs2[keys2[i]]:
            a = divs1[keys1[i]]
            b = divs2[keys2[i]]
        else:
            a = divs2[keys2[i]]
            b = divs1[keys1[i]]
        if a%b != 0:
            return False
        if e == -1:
            e = a/b
            if e > n:
                return False
            if e < 2:
                return False
        else:
            if e != a/b:
                return False
    return True

def hash_v(d):
    skeys = sorted(d.keys())
    out = "".join([str(k) for k in skeys])
    out += "_"
    for k in skeys:
        out += str(d[k])
        out += "_"
    print out
    return out

def exponentiate(divs, e):
    out = {}
    for k, v in divs.iteritems():
        out[k] = v*e
    return out

if __name__ == "__main__":
    import sys
    divs = []
    n = int(sys.argv[1])
    for k in range(2, n+1):
        divs.append(list_dividers(k))
    print divs
    nb = 0
    counter = {}
    for i, d in enumerate(divs):
        for b in range(2,n+1):
            exp = exponentiate(d, b)
            # print exp
            h = hash_v(exp)
            if not h in counter:
                counter[h] = 0
                # print exp
            counter[h]+=1

    print len(counter)

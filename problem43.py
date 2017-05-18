import copy


def is_unidigital(k):
    d1, d2, d3 = k/100, (k/10) % 10, k % 10
    if d1 == d2 or d2 == d3 or d1 == d3:
        return False
    return True


def list_pan(l_divs, out, digits=[0]*10, current=[]):
    if len(l_divs) == 0:
        out.append(copy.deepcopy(current))
        return
    div = l_divs[0]
    if len(current) == 0:
        last = None
    else:
        last = current[0]
    print "div is {} {} {} {}".format(div, l_divs, digits, last)
    print current
    for k in range(div, 1000, div):
        if is_unidigital(k):
            d1, d2, d3 = k/100, (k/10) % 10, k % 10
            if digits[d1] == 0 and digits[d2] == 0 and digits[d3] == 0:
                if last is not None:
                    print k, k % 100, last/10
                if last is None or k % 100 == last/10:
                    print k
                    # digits[d1] = 1
                    # digits[d2] = 1
                    digits[d3] = 1
                    # current.insert(0, k)
                    print "l_divs has size {} ".format(len(l_divs))
                    list_pan(l_divs[1:], out, digits, [k] + current)
                    # digits[d1] = 0
                    # digits[d2] = 0
                    digits[d3] = 0
                    # current = current[1:]


l = []
list_pan([17, 13, 11, 7, 5, 3, 2], l)
print l
sol = []
for digs in l:
    i = 3
    n = digs[-1]
    d = range(10)
    d.remove(n/100)
    d.remove(n/10 % 10)
    d.remove(n % 10)
    print digs
    for k in range(len(digs)-2, -1, -1):
        u = digs[k]
        t = (u/100)
        print t
        n += t*(10**i)
        d.remove(t)
        i += 1
    print d
    assert(len(d) == 1)
    n += d[0]*(10**i)

    sol.append(n)
print sol
print sum(sol)
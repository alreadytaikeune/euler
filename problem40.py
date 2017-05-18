
def get_length_for_tenth(n):
    if n == 0:
        return 1
    if n == 1:
        return 9
    return n*(10**n - 10**(n-1))


l = []
i = 0
k = 0
while k < 1000000:
    k += get_length_for_tenth(i)
    i += 1
    l.append(k)
print l
# idxs = [1, 10, 100, 1e3, 1e4, 1e5, 1e6]
idxs = [1, 10, 100, 1000, 10000, 100000, 1000000]
res = 1
idx_in_l = 0
for t, i in enumerate(idxs):
    if t <= 1:
        continue
    while l[idx_in_l] <= i:
        idx_in_l += 1
    if idx_in_l < len(l):
        n = i-l[idx_in_l-1]
        r = idxs[t-1] + (n/t)
        print r
        print n/t
        r = r/int(10**(t - n % t - 1)) % 10
        print i, r
        res *= r

print res

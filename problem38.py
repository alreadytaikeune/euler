from math import floor, ceil
# n*100000+2*n < 1e9
# n*100000+2*n >= 1e8
# n*100002

# n*1e6+2*n*1e3+3*n < 1e9
# n*1e6+2*n*1e3+3*n >= 1e8

# n*(1003002)
# 2 2 2 3
# n*1e7 + 2*n*1e5 + 3*n*1e3 + 4*n
# n*10203004
# 1 2 2 2 2
# n*1e8 + 2*n*1e6 + 3*n*1e4 + 4*n*1e2 + 5*n
# n*102030405
# 1 1 1 2 2 2
# n*123040506
# 1 1 1 1 1 2 2
# n*123450607
# 1 1 1 1 1 1 1 2
# n*123456708
# n*123456789

dens = [100002., 1003002., 10203004., 102030405., 123040506., 123450607.,
        123456708., 123456789.]
limits = [(int(ceil(123456789/x)), int(floor(987654321/x))) for x in dens]
print limits


def is_pandigital(n):
    digits = [0]*10
    for c in str(n):
        i = int(c)
        if i == 0:
            return False
        if digits[i] == 1:
            return False
        digits[i] = 1
    return sum(digits) == 9

max_found = 0
ref_nb = 0
for k, (i_l, i_m) in enumerate(limits):
    # print k, (i_l, i_m)
    s = ""
    for n in range(1, 3+k):
        s += str(n*i_l)
    nb = int(s)
    print nb
    for n in range(1, 3+k):
        s += str(n*i_m)
    nb = int(s)
    print nb
    for i in range(i_l, i_m+1):
        s = ""
        for n in range(1, 3+k):
            s += str(n*i)
        nb = int(s)
        # print nb
        if nb > 987654321:
            break
        if nb < 123456789:
            continue
        if is_pandigital(nb):
            print "found {}, {}".format(nb, k)
            if nb > max_found:
                max_found = nb
                ref_nb = (k, i)
print max_found
print ref_nb

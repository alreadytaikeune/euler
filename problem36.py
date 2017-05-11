
def is_palindrom(s):
    n = len(s)
    for i in range(n/2):
        if s[i] != s[n-1-i]:
            return False
    return True


tmp = [(i, 1) for i in range(10)]+[(i*11, 2) for i in range(1, 10)]
nb_digits_max = 7
sum_pal = 0
while len(tmp) > 0:
    i, nb_digits = tmp.pop()
    # print i
    if is_palindrom("{0:b}".format(i)):
        print i, "{0:b}".format(i)
        sum_pal += i
    if nb_digits + 2 >= nb_digits_max:
        continue
    for k in range(1, 10):
        pal = i*10 + k*10**(nb_digits+1) + k
        # print i, pal
        tmp.insert(0, (pal, nb_digits+2))
        if nb_digits + 4 < nb_digits_max:
            pal = i*100 + k*10**(nb_digits+3) + k
            # print i, pal
            tmp.insert(0, (pal, nb_digits+4))
    if nb_digits % 2 == 0:
        r = i % 10**(nb_digits/2)
        l = i-r
        pal = l*100 + r
        # print i, pal
        tmp.insert(0, (pal, nb_digits+2))
print sum_pal

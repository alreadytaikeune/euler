
def list_digits(n):
    out = []
    while n > 0:
        out.append(n%10)
        n /= 10
    return out


if __name__ == "__main__":
    out = 0
    for n in range(2, 1000000):
        if n == sum([x**5 for x in list_digits(n)]):
            out += n
    print out
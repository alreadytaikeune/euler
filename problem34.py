
def get_digits(n):
    out = []
    while n > 0:
        out.insert(0, n%10)
        n /= 10
    return out

def verifies_condition(n, facts):
    digits = get_digits(n)
    # print digits
    s = 0
    for k in digits:
        s += facts[k]
        if s > n:
            return False
    return s == n


if __name__ == "__main__":
    facts = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
    out = []
    for j in range(20, 10**7):
        if verifies_condition(j, facts):
            out.append(j)
    print out


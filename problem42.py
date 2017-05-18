with open("p042_words.txt", "r") as _:
    content = _.read()
    words = [w[1:-1] for w in content.split(",")]

def get_value(w):
    tmp = 0
    for c in w:
        tmp += ord(c) - 64
    return tmp

m = 0
for w in words:
    v = get_value(w)
    if v > m:
        m = v

triangs = set()
n = 1
while n*(n+1)/2 < m:
    triangs.add(n*(n+1)/2)
    n += 1

count = 0
for w in words:
    if get_value(w) in triangs:
        count += 1
print count

def write_in_words(n, units, tens):
    if n < 10:
        return units[n]
    elif n < 20:
        return tens[n]
    elif n < 100:
        if n%10==0:
            return tens[n/10]
        return tens[n/10] + units[n%10]
    elif n == 100:
        return "onehundred"
    elif n < 1000:
        if n%100==0:
            return units[n/100] + "hundred"
        return units[n/100] + "hundredand" + write_in_words(n%100, units, tens)
    elif n == 1000:
        return "onethousand"

if __name__ == "__main__":
    units = {1: "one", 2: "two", 3:"three", 4:"four", 5:"five",
    6:"six", 7:"seven", 8:"eight", 9:"nine"}
    tens = {10: "ten", 11: "eleven", 12:"twelve", 13:"thirteen", 14:"fourteen",
    15:"fifteen", 16:"sixteen", 17:"seventeen", 18:"eighteen", 19:"nineteen", 
    2:"twenty", 3: "thirty", 4:"forty", 5:"fifty", 6:"sixty", 7:"seventy", 8:"eighty",
    9:"ninety"}
    n = 0
    print len(write_in_words(342, units, tens))
    print len(write_in_words(115, units, tens))
    for i in range(1, 1001):
        s = write_in_words(i, units, tens)
        n+=len(s)
        # print s
    print n

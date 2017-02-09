import numpy as np
import sys

if __name__ == "__main__":
    n = int(sys.argv[1])
    backtrace = np.zeros((n+1, 8), dtype="int64")
    coins = [1, 2, 5, 10, 20, 50, 100, 200]
    for y in range(n+1):
        backtrace[y, 0] = 1

    for y in range(n+1):
        for x in range(1, len(coins)):
            if y >= coins[x]:
                backtrace[y, x] += backtrace[y-coins[x], x]
                backtrace[y, x] += backtrace[y, x-1]
            else:
                backtrace[y, x] = backtrace[y, x-1]

    print backtrace

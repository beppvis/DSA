def aPowerN(a, n):
    # Base Case
    if n == 0:
        return 1

    # Recursive Case
    else:
        return a * aPowerN(a, n - 1)


print(aPowerN(3, 2))

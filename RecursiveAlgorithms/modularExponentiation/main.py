# (x^n)*mod(M)
def mod(x, n, M):
    # base case
    if n == 0:
        return 1
    # if n is even
    elif n % 2 == 0:
        y = mod(x, n/2, M)
        return (y * y) % M
    # if n is odd
    else:
        return ((x % M)*mod(x, n-1, M)) % M


# example

print(mod(5, 3, 7))

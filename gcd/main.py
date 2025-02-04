# a < b is asumed
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


# examples
x = gcd(42, 69)
print(x)

y = gcd(10, 40)
print(y)

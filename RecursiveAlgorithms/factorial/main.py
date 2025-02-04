def factorial(n):
    # Base Case
    if n == 0 or n == 1:
        return 1

    # Recursive Case
    else:
        return n * factorial(n - 1)


print(factorial(5))

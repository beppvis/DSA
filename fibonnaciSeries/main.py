
def fibo(n):
    if n == 0:
        return []
    if n == 1:
        return [0]
    if n == 2:
        return [0, 1]
    l = [0, 1]

    for i in range(1, n):
        l.append(l[i]+l[i-1])

    return l


n = int(input("Enter a number : "))
print(fibo(n))

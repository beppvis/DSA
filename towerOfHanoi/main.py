def towerOfHanoi(n, src, dest, aux):
    if n == 0:
        return
    towerOfHanoi(n-1, src, aux, dest)
    print("Moving", n, "from", src, "to destination", dest)
    towerOfHanoi(n-1, aux, dest, src)


n = int(input("Enter number of disks : "))
towerOfHanoi(n, 'A', 'B', 'C')

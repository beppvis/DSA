def towerOfHanoi(n, src, dest, aux):
    if n == 1:
        print("Moving 1 ", "from ", src, "putting it in", dest)
        return
    towerOfHanoi(n-1, src, aux, dest)
    print("Moving", n, "from", src, "to destination", dest)
    towerOfHanoi(n-1, aux, dest, src)


n = int(input("Enter number of disks : "))
towerOfHanoi(n, 'A', 'B', 'C')

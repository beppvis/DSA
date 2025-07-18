def highWindow(A):
    l1 = len(A)
    max_size = 0
    size = 0
    if (l1<=1): return l1

    for i in range(0,l1-1):
        size = size+1
        if A[i]>=A[i+1]:
            max_size = max(max_size,size)
            size=0

    return max_size

print(highWindow([8,5,3,7,0,2,1,9,11,4,3,5]))
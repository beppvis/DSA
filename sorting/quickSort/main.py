


def partion(arr,p,q):
    pivot = arr[p]
    slow = p
    fast = slow + 1
    while fast < q:
        if (pivot > arr[fast]):
            temp = arr[slow + 1]
            arr[slow+1] = arr[fast]
            arr[fast] = temp
            slow += 1
        fast += 1
    temp = arr[p]
    arr[p] = arr[slow]
    arr[slow] = temp
    return slow


def quickSort(A,s,e):
    if (s < e):
        m = partion(A,s,e)
        quickSort(A,s,m-1)
        quickSort(A,m+1,e)
    return A

print(quickSort([10,3,5,4],0,4))




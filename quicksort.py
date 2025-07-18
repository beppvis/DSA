def partition(A:list,p:int,q:int):
    pivot = A[p]
    slow = p
    fast  = slow + 1
    while fast <= q:
        if pivot > A[fast]:
            temp = A[fast]
            A[fast] =A[slow+1]  
            A[slow+1] = temp  
            slow +=1
        fast +=1
    temp = A[p]
    A[p] = A[slow]
    A[slow] = temp
    return slow

def quickSort(A:list,s:int,e:int):
    if (s < e):
        m = partition(A,s,e)
        quickSort(A,s,m-1)
        quickSort(A,m+1,e)
    return A



a = [1,5,2,8,3,9]
print(quickSort(a,0,len(a)-1))



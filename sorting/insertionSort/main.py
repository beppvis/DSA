def insertion( arr,n):
    for curr in range(1,len(arr)):
        left = curr - 1
        key = arr[curr]
        while (left >= 0 and  key < arr[left]):
            arr[left+1] = arr[left]
            left -=1
        
        arr[left+1] = key
    return arr

print(insertion([10,20,12],1))
    
   

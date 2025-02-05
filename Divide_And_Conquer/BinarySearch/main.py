# arr -> list
# high -> the highest index
# low -> the lowest index
# x -> the target element ie, the element we are looking for
# this alogrithm assumes that arr is sorted
def binary_search(arr, high, low, x):
    if  low <= high:

        mid = (high+low)//2
        
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            high = mid - 1
        else:
            low = mid + 1
        return binary_search(arr, high, low, x)
    
    # -1 means the item x could not be found
    return -1

# example
arr = [1, 2, 3, 4, 10, 11, 15, 23]
i = binary_search(arr, len(arr)-1, 0, 15)
print(i)
# arr -> list
# high -> the highest index
# low -> the lowest index
# x -> the target element ie, the element we are looking for
# this alogrithm assumes that arr is sorted
def binary_search(arr, high, low, x):

    while low <= high:
        mid = low + (high-low)//2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            mid -= 1
        else:
            mid += 1

    # -1 means the item x could not be found
    return -1


# example
arr = [1, 2, 3, 4, 10, 23]
i = binary_search(arr, len(arr)-1, 0, 23)
print(i)

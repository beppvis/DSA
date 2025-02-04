def MergeSort(arr):
    # Base case
    if len(arr) <= 1:
        return arr

    # Recursive case: divide the array
    mid = len(arr) // 2
    leftHalf = MergeSort(arr[:mid])
    rightHalf = MergeSort(arr[mid:])

    return Merge(leftHalf, rightHalf)


# sorts the small subarrays and combines them
def Merge(left, right):
    sortedArr = []
    i, j = 0, 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            sortedArr.append(left[i])
            i += 1
        else:
            sortedArr.append(right[j])
            j += 1

    # Append the remaining elements to the sorted list
    sortedArr.extend(left[i:])
    sortedArr.extend(right[j:])

    return sortedArr


arr = [38, 27, 43, 3, 9, 82, 10]
sorted_arr = MergeSort(arr)
print("Sorted array:", sorted_arr)

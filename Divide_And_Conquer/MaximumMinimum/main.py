
def MinMaxDac(A, l_index, r_index):
    # if there there is only one element
    if (r_index == l_index):
        return (A[r_index], A[l_index])

    # Cheking if there are only two elements
    elif ((r_index - l_index) == 1):
        # getting the min and max, by comparing the two
        if (A[r_index] > A[l_index]):
            return (A[l_index], A[r_index])
        else:
            return (A[r_index], A[l_index])

    else:
        # calculating the middle index
        # NOTE : floor division is used because you
        #       cant index an array with floats
        mid = (r_index+l_index)//2
        # from the left to middle
        LMin, LMax = MinMaxDac(A, l_index, mid)
        # from the middle + 1 to right
        RMin, RMax = MinMaxDac(A, mid + 1, r_index)
        min, max = (0, 0)

        if (LMax > RMax):
            max = LMax
        else:
            max = RMax
        if (LMin < RMin):
            min = LMin
        else:
            min = RMin

        return (min, max)


# example

A = [10, 20, 30, 40, 50]
print("Original array : ", A)
print(MinMaxDac(A, 0, len(A)-1))

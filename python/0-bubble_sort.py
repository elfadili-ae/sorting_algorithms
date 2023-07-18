#!/usr/bin/python3

def bubble_sort(array, size):
    if size == 0 or size == 1:
        return

    bubbled = True
    count = 0
    while bubbled == True:
        count += 1
        bubbled = False
        for j in range(size - 1):
            count += 1
            if array[j] > array[j + 1]:
                tmp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = tmp
                print(array)
                bubbled = True
    print("[{}]".format(count))


"test"

"best case"
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
bubble_sort(array, len(array))

print("-----------")

"avg case"
array = [7, 2, 10, 4, 5, 8, 1, 6, 3, 9]
bubble_sort(array, len(array))

print("-----------")

"worst case"
array = [-1, -2, -3, -4, -5, -6, -7, -8, -9, -10]
bubble_sort(array, len(array))

import random
from typing import List

def merge_sort(arr: List[int]) -> None:
    if len(arr) == 1:
        return
        
    l = 0
    r = len(arr) - 1
    mid = l + (r - l) // 2
    
    left_arr = arr[l:mid + 1]
    right_arr = arr[mid + 1:r + 1]
    
    merge_sort(left_arr)
    merge_sort(right_arr)
    merge(arr, left_arr, right_arr)

def merge(arr: List[int], left_arr: List[int], right_arr: List[int]) -> None:
    left_size, right_size = len(left_arr), len(right_arr)
    i, j, k = 0, 0, 0
    
    while i < left_size and j < right_size:
        if left_arr[i] <= right_arr[j]:
            arr[k] = left_arr[i]
            i += 1
        else:
            arr[k] = right_arr[j]
            j += 1
        k += 1
    
    #leftovers
    while i < left_size:
        arr[k] = left_arr[i]
        i += 1
        k += 1
    
    while j < right_size:
        arr[k] = right_arr[j]
        j += 1
        k += 1

    
def main():
    test_list = []
    size = 10
    for i in range(size):
        test_list.append(random.randint(0, ))
        
    #unsorted
    print(test_list)
    
    merge_sort(test_list)
    
    #sorted
    print(test_list)
    

if __name__ == "__main__":
    main()
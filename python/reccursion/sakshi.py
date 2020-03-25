# 1. Choose a pivot
# 2. Make the pivot reach its right place
#    This is done by finding the no. of elements smaller than the pivot
#    For eg: [4, 5, 7, 2, 1, 9, 3], suppose 4 is choosed as the pivot,
#    Here 3 elements are smaller than 4 (i.e. 1,2 and 3), therefore its place is index 4
# 3. Now, ensure that all the elements smaller than the pivot is at its left side and all the
#    elements larger than it are at the right side.
# 4. Call QuickSort() at both the left half (sublist) and right half of the original list.  

import sys
sys.setrecursionlimit(5000)


# getting user input
user_input = input("Enter a list of integers to sort (space separated values) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]


def partition(arr,si,ei):
    count=0
    for i in range(si,ei+1):
        if arr[i]<arr[si]:
            count+=1
           
    arr[count+si],arr[si]=arr[si],arr[count+si] 
    i=si
    j=ei
    while i<count: # +si:
        if arr[i]<=arr[count+si]:
            i=i+1
        else:
            while j>count: #+si:
                if arr[j]>arr[count+si]:
                    j=j-1
                else:
                    arr[i],arr[j]=arr[j],arr[i]
                    j=j-1
                    #i=i+1
                    break
            i = i + 1
                 
    return count + si     
                
def quickSort(arr, start, end):
    if start>=end:
        return arr 
    p=partition (arr,start,end)
    quickSort(arr,start,p-1)
    quickSort(arr,p+1,end)
    return arr


final_list = quickSort(input_list, 0, len(input_list) - 1)
print(final_list)

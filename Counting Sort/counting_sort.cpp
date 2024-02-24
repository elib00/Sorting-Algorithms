#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int getMax(int *arr, int size){
    int maxElement = arr[0];
    for(int i = 1; i < size; i++){
        maxElement = max(arr[i], maxElement);
    }

    return maxElement;
}


int *counting_sort(int *arr, int size){
    //get the max element from the array to get the range of elements
    int maxElement = getMax(arr, size);
   
    //create a lookup table
    int N = maxElement + 1;
    int *freq = (int*) calloc(N, sizeof(int));

    //get the frequency of the elements in the array
    for(int i = 0; i < size; i++){
        freq[arr[i]]++;
    }

    //convert the frequency array to a running sum array (lol pwede ra sad maghimo og lain na array)
    for(int i = 1; i < N; i++){
        freq[i] += freq[i - 1];
    }

    //create an array for the sorted elements, assign the values of the array to -1 (assuming that the provided values of the original array are greater than or equal to zero)
    int *sortedArray = (int*) malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        sortedArray[i] = -1;
    }
    
    //iterate over the original array and find its new index in the lookup table
    for(int i = 0; i < size; i++){
        int index = freq[arr[i]]- 1;
        if(index >= 0){
            sortedArray[index] = arr[i];
        }
    }

    //sanitizing the sorted array (filling the spaces for duplicate elements)
    for(int i = size - 1; i >= 0; i--){
        if(sortedArray[i] == -1){
            sortedArray[i] = sortedArray[i + 1];
        }
    }


    return sortedArray;
}

int main(void){
    int arr[] = {1, 9, 0, 4, 5, 8, 9,};
    int size = sizeof(arr) / sizeof(int);
    int *sortedArray = counting_sort(arr, size);

    for(int i = 0; i < size; i++){
        cout << sortedArray[i] << " ";
    }

    return 0;
}
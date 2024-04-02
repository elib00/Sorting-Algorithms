#include <iostream>
// #include "./Algorithms/counting_sort.cpp"
// #include "./Algorithms/merge_sort.cpp"
#include "./Algorithms/quick_sort.cpp"

using namespace std;

int main(void){
    int arr[] = {1231, 4, 5, 1, 4, 1, 2, 5, 6 , 8, 100};
    int size = sizeof(arr) / sizeof(int);
    SortingAlgorithm *sortingAlgo = new QuickSort(arr, size);

    int *sortedArr = sortingAlgo->sort();
    for(int i = 0; i < size; i++){
        cout << sortedArr[i] << " ";
    }
    
    return 0;
}
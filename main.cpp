#include <iostream>
// #include "./Algorithms/counting_sort.cpp"
#include "./Algorithms/merge_sort.cpp"

using namespace std;

int main(void){
    int arr[] = {1231, 4, 5, 1, 4, 1, 2, 5, 6 , 8, 100};
    int size = sizeof(arr) / sizeof(int);
    SortingAlgorithm *sortingAlgo = new MergeSort(arr, size);

    int *newArr = sortingAlgo->sort();
    for(int i = 0; i < size; i++){
        cout << newArr[i] << " ";
    }
    
    return 0;
}
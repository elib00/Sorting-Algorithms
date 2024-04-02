//visualization referenec - https://youtu.be/WprjBK0p6rw?si=XgTcH_3caIv8GvB9

#include "sorting_algorithm.cpp"

using namespace std;

class QuickSort : public SortingAlgorithm {
    int *array;
    int size;

    void sort(int *array, int start, int pivot){
        if(start >= pivot) return;

        int pivotElem = array[pivot];
        int newPivot = start - 1;

        for(int i = start; i <= pivot; i++){
            int currElem = array[i];
            if(currElem > pivotElem){
                continue;
            }else{
                if(i == newPivot) continue;
                newPivot++;
                swap(array[i], array[newPivot]);
            }
        }

        sort(array, start, newPivot - 1);
        sort(array, newPivot + 1, pivot);
    }

    public:
        QuickSort(int *array, int size){
            this->array = array;
            this->size = size;
        }

        int *sort(){
            sort(array, 0, size - 1);
            int *sortedArray = new int[size];
            copy(array, array + size, sortedArray);
            return sortedArray;
        }
};
#include "sorting_algorithm.cpp"

using namespace std;

class MergeSort : public SortingAlgorithm {
    int *array;
    int size;

    void sort(int *array, int size){
        if(size == 1) return;
        int l = 0, r = size - 1;
        int mid = l + (r - l) / 2;

        int leftHalfSize = mid + 1;
        int rightHalfSize = size - leftHalfSize;

        int *leftHalf = new int[leftHalfSize];
        int *rightHalf = new int[rightHalfSize];

        copy(array, array + (mid + 1), leftHalf);
        copy(array + (mid + 1), array + size, rightHalf);

        sort(leftHalf, leftHalfSize);
        sort(rightHalf, rightHalfSize);
        merge(array, leftHalf, leftHalfSize, rightHalf, rightHalfSize);

        delete[] leftHalf;
        delete[] rightHalf;
    }

    void merge(int *array, int *leftHalf, int leftHalfSize, int *rightHalf, int rightHalfSize){
        int i = 0, j = 0, k = 0;

        while(i < leftHalfSize && j < rightHalfSize){
            if(leftHalf[i] <= rightHalf[j]){
                array[k] = leftHalf[i++];
            }else{
                array[k] = rightHalf[j++];
            }

            k++;
        }

        //leftovers
        while(i < leftHalfSize){
            array[k++] = leftHalf[i++];
        }

        while(j < rightHalfSize){
            array[k++] = rightHalf[j++];
        }
    }


    public:
        MergeSort(int *array, int size){
            this->array = array;
            this->size = size;
        }
        
        int *sort(){
            sort(array, size);
            int *sortedArray = new int[size];
            copy(array, array + size, sortedArray);
            return sortedArray;
        }

};
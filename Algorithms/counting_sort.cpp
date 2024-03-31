#include <climits>
#include <algorithm>
#include <cstdlib>
#include "sorting_algorithm.cpp"

using namespace std;

class CountingSort : public SortingAlgorithm {
    int *array;
    int size;

    int getMax(){
        int mx = INT_MIN;
        for(int i = 0; i < size; i++){
            mx = max(array[i], mx);
        }

        return mx;
    }

    public:
        CountingSort(int *array, int size){
            this->array = array;
            this->size = size;
        }

        int *sort(){
            //first get the max value in the array;
            int mx = getMax();

            //initialize hashtable
            int *hashtable = (int*) calloc(mx + 1, sizeof(int)); //all zeros

            //initialize prefix array
            int *prefix = (int*) calloc(mx + 1, sizeof(int));

            //get the frequencies;
            for(int i = 0; i < size; i++){
                hashtable[array[i]]++;
            }

            //accumulate the prefix sum
            prefix[0] = hashtable[0];
            for(int i = 1; i <= mx; i++){
                prefix[i] = prefix[i - 1] + hashtable[i];
            }

            //create the new array
            int *newArray = (int*) malloc(size * sizeof(int));

            //0 8 6 3
            //start from the end of the original array;
            for(int i = size - 1; i >= 0; i--){
                int index = prefix[array[i]] - 1;
                newArray[index] = array[i];
                prefix[array[i]]--;
            }

            free(hashtable);
            free(prefix);

            return newArray;

        }
};
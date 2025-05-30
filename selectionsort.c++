#include <iostream>

using namespace std;


void selectionSort(int array[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1;j < n;j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            swap(array[i], array[min]);
        }
    }
}

void insertionSort(int array[], int n){
    for(int i = 1; i < n; i++){
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void bubbleSort(int array[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            if(array[j] > array[j + 1]){
                swap(array[j] > array[j+1]);
            }
        }
    }
}

int partition(int array[], int start, int end){
    int i = start;
    int j = end;
    int pivot_value = array[(start + end) / 2];
    bool finished = false;
    while(!finished){
        while(array[i] < pivot_value){
            i++;
        }
        while(array[j] > pivot_value){
            j--;
        }
        if(i < j){
            swap(array[i], array[j]);
            if(array[i] == array[j]){
                i++;
            }
        }
        else{
            finished = true;
        }
    }
    return i;

}

void quicksort(int array[], int start, int end){
    if(start < end){
        int pivot_index = partition(array, start, end);
        quicksort(array, start, pivot_index - 1);
        quicksort(array, pivot_index + 1, end);
    }
}

int main(){


    return 0;
}
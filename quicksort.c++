#include <iostream>
#include <stdlib.h>

using namespace std;


void SwapIndex(int array[], int i, int j){
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}


void merge(int arr[], int l, int m , int r){
    int i = l;
    int j = m + 1;
    int k = l;

    int temp[5] = {};

    while(i <= m && j <= r){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= m){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= r){
        temp[k] = arr[j];// j
        j++;
        k++;
    }

    for(int s = l; s <= r; s++){ //<=
        arr[s] = temp[s]; //temp was arr
    }

}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

}

int partition(int array[], int start, int end){
    int i = start;
    int j = end;

    int pivot_value = array[(start + end) / 2];
    bool finished = false;
    while(!finished){
        while((i<end) && (array[i] <= pivot_value)){
            i++;
        }
        if(i < j){
            SwapIndex(array, i, j);
        }
        else{
            finished = true;
        }
    }


}

void quicksort(int array[], int start, int end){
    if(start < end){
        int pivot_index = partition(array, start, end);
            quicksort(array, start, pivot_index -1);
            quicksort(array, pivot_index + 1, end);
    }
}

int main(){

    int a[5] = {3,4,0,2,1};
    int size = 5; //why does this make it work but not work
    cout << "Before Merge Sort: " << endl;
    for(int i = 0; i < 5; i++){
        cout << a[i] <<" ";
    }

    mergeSort(a, 0, 5);

    cout<< endl << "After Merge Sort: " << endl;
    for(int i = 0; i < 5; i++){
        cout<< a[i] << " ";
    }

    return 0;
}
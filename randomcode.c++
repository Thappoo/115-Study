#include <iostream>

using namespace std;

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int temp = array[i]; 
        int j = i - 1;

        while(j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
}

int main(){

    return 0;
}
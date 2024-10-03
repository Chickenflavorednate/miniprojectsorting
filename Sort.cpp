//
// Created by Leighanne on 11/2/2023.
//

#include "Sort.hpp"

Sort::Sort() {
	comparisons = 0;
	moves = 0;
}

void Sort::insertion_sort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            comparisons++;
            moves++;
        }

        array[j + 1] = key;
        moves++;
    }
}

//void Sort::insertion_sort(int *array, int size) {
//    int i, key, j;
//
//    for(i = 1; i < size; i++){
//        key = array[i];
//        j = i - 1;
//    }
//
//    while(j >= 0 && array[j] > key){
//        //elements that are greater than key move one
//        // position ahead of their current position
//        array[j+1] = array[j];
//        j = j - 1;
//    }
//
//    array[j + 1] = key;
//
//}

void Sort::merge_sort(int *array, int size) {
    if (size > 1) {
        int middle = size / 2;
        merge_sort(array, middle);
        merge_sort(array + middle, size - middle);
        merge(array, 0, middle - 1, size - 1);
    }
//    if (size <= 1){
//        return;
//    }
//
//    int mid, leftSize, rightSize;
//
//    mid = size / 2;
//    leftSize = mid;
//    rightSize = size - mid;
//
//    //create the left and right subarrays
//    int *leftArray = new int[leftSize];
//    int *rightArray = new int[rightSize];
//
//    for(int i = 0; i < leftSize; i++){
//        leftArray[i] = array[i];
//    }
//
//    for(int i = 0; i < rightSize; i++){
//        rightArray[i] = array[mid + 1];
//    }
//
//    //recursive calls for the left and right subarrays
//    merge_sort(leftArray, leftSize);
//    merge_sort(rightArray, rightSize);

}

void Sort::merge_insert_sort(int *array, int size) {
    const int INSERTION_THRESHOLD = 10;

    if (size > INSERTION_THRESHOLD) {
        int middle = size / 2;
        merge_insert_sort(array, middle);
        merge_insert_sort(array + middle, size - middle);
        merge(array, 0, middle - 1, size - 1);
    } else {
        insertion_sort(array, size);
    }
}

void Sort::merge_sort(int *array, int start, int end) {

}

void Sort::merge(int *array, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    // Create temporary arrays for the left and right subarrays
    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[start + i];
    }

    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0;  // Initial index of the left subarray
    int j = 0;  // Initial index of the right subarray
    int k = start;  // Initial index of the merged subarray

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Free the memory used for temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

int Sort::getComparisons() {
	return comparisons;
}

int Sort::getMoves() {
	return moves;
}

void Sort::swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

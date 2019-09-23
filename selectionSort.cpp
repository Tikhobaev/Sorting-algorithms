//
// Created by Илья on 015 15.09.19.
//
#include "selectionSort.h"
void selectionSort(vector<double>& arr, int n){
    for (int i = 0; i < n; i++){
        double min = arr[i];
        int minIndex = i;
        for (int j = i; j < n; j++){
            if (arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
        }
        double tmp = arr[i];
        arr[i] = min;
        arr[minIndex] = tmp;
    }
}
//
// Created by Илья on 015 15.09.19.
//

#include "quickSort.h"
void quickSort(vector<double>& arr, int left, int right)
{
    double pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = arr[left];
    while (left < right)
    {
        while ((arr[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            arr[left] = arr[right];
            left++;
        }
        while ((arr[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(arr, left, pivot - 1);
    if (right > pivot)
        quickSort(arr, pivot + 1, right);
}


void quickSortWorstPivot(vector<double>& arr, int left, int right)
{
    double pivot;
    int l_hold = left;
    int r_hold = right;
    double maxElem = arr[left];
    int maxInd = left;
    for (int i = left; i <= right; i++){
        if (arr[i] > maxElem){
            maxElem = arr[i];
            maxInd = i;
        }
    }
    double tmp = arr[left];
    arr[left] = maxElem;
    arr[maxInd] = tmp;
    pivot = arr[left];
    while (left < right)
    {
        while ((arr[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            arr[left] = arr[right];
            left++;
        }
        while ((arr[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSortWorstPivot(arr, left, pivot - 1);
    if (right > pivot)
        quickSortWorstPivot(arr, pivot + 1, right);
}
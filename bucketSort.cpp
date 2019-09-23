//
// Created by Илья on 015 15.09.19.
//

#include "bucketSort.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void bucketSort(vector<double>& arr, int n)
{
    struct bucket buckets[n / 3];
    int i, j, k;
    for (i = 0; i < n / 3; i++)
    {
        buckets[i].count = 0;
    }
    double max = arr[0], min = arr[0];
    for(int i = 0; i < n; i++){
        if (arr[i] < min){
            min = arr[i];
        }
        if (arr[i] > max){
            max = arr[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        int bucketNum = int((arr[i] - min) / ((max - min) / (n/3)));
        if (bucketNum >= n/3) {
            bucketNum = n/3 - 1;
        }
        buckets[bucketNum].value.push_back(arr[i]);
        buckets[bucketNum].count++;
    }
    for (k = 0, i = 0; i < n/3; i++)
    {
        // now using quicksort to sort the elements of buckets
        sort(buckets[i].value.begin(), buckets[i].value.end());
        for (j = 0; j < buckets[i].count; j++)
        {
            arr[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
    }
}
//
// Created by Илья on 015 15.09.19.
//
#include <vector>
#include <time.h>
#include <iostream>
#include "selectionSort.h"
#include "bucketSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "timSort.h"
using  namespace std;
#ifndef CLION_PROJECTS_TEST_H
#define CLION_PROJECTS_TEST_H

void getTestVectorDouble(vector<double>& arr, int max, int num);
void selectionSortTest();
void bucketSortTest();
void quickSortTest();
void mergeSortTest();
void timSortTest();

#endif //CLION_PROJECTS_TEST_H

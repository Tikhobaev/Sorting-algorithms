//
// Created by Илья on 015 15.09.19.
//

#ifndef CLION_PROJECTS_TIMSORT_H
#define CLION_PROJECTS_TIMSORT_H

#include <vector>
#include <string.h>
using namespace std;

int binSearch(double val, vector<double>& arr, int start, int count);
void timSort(vector<double> &arr, int len);
void merge(vector<double> &arr, int fStart, int fLength, int sStart, int sLength);
void insertionSort(vector<double>& arr, int start, int end);
int getMinrun(int n);

#endif //CLION_PROJECTS_TIMSORT_H

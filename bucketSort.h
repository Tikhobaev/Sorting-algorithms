//
// Created by Илья on 015 15.09.19.
//

#ifndef CLION_PROJECTS_BUCKETSORT_H
#define CLION_PROJECTS_BUCKETSORT_H
#include <vector>
#include <algorithm>
using namespace std;
struct bucket
{
    int count;
    vector <double> value;
};

void bucketSort(vector<double>& arr, int n);

#endif //CLION_PROJECTS_BUCKETSORT_H

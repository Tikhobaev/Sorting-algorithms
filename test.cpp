//
// Created by Илья on 015 15.09.19.
//
#include "test.h"

void getTestVectorDouble(vector<double>& arr, int max, int num){
    srand(time(NULL));
    for (int i = 0; i < num; i++){
        arr.push_back(((double)rand() / RAND_MAX) * max);
    }
}

void selectionSortTest(){
    vector <double> arr;

    cout << " Selection sort:" << endl;
    for (int n = 10; n <= 100000; n *= 10){
        cout << endl << n << " elements " << endl;
        double midTime = 0;
        int k = 50;  // count of test arrays
        for (int i = 0; i < k; i++){
            getTestVectorDouble(arr, 100, n);

            double start = clock();
            selectionSort(arr, n);
            double end = clock();

            midTime += (end - start) / CLOCKS_PER_SEC;
            for (int c = 0; c < n - 1; c++){
                if (arr[c] > arr[c + 1]){
                    cout << endl << "Error: there are unsorted elements!!!" << endl;
                }
            }
            arr.clear();
        }
        cout << " time: " << midTime / k << " sec.";
    }
}

void bucketSortTest(){
    vector <double> arr;
    cout << " Bucket sort:" << endl;
    for (int n = 10; n <= 100000; n *= 10){
        cout << endl << n << " elements " << endl;
        double midTime = 0;
        int k = 50;  // count of test arrays
        for (int i = 0; i < k; i++){
            getTestVectorDouble(arr, 100, n);
            double start = clock();
            bucketSort(arr, n);
            double end = clock();
            midTime += (end - start) / CLOCKS_PER_SEC;
            for (int c = 0; c < n - 1; c++){
                if (arr[c] > arr[c + 1]){
                    cout << endl << "Error: there are unsorted elements!!!" << endl;
                }
            }
            arr.clear();
        }
        cout << " time: " << midTime / k << " sec.";
    }
}


void quickSortTest(){
    vector <double> arr;

    cout << " Quick sort(random pivot):" << endl;
    for (int n = 10; n <= 100000; n *= 10){
        cout << endl << n << " elements " << endl;
        double midTime = 0;
        int k = 50;  // count of test arrays
        for (int i = 0; i < k; i++){
            getTestVectorDouble(arr, 100, n);
            double start = clock();
            quickSort(arr, 0, n - 1);
            double end = clock();

            midTime += (end - start) / CLOCKS_PER_SEC;
            for (int c = 0; c < n - 1; c++){
                if (arr[c] > arr[c + 1]){
                    cout << endl << "Error: there are unsorted elements!!!" << endl;
                }
            }
            arr.clear();
        }
        cout << " time: " << midTime / k << " sec.";
    }

    cout << endl <<" Quick sort(worst pivot):" << endl;
    for (int n = 10; n <= 100000; n *= 10){
        cout << endl << n << " elements " << endl;
        double midTime = 0;
        int k = 50;  // count of test arrays
        for (int i = 0; i < k; i++){
            getTestVectorDouble(arr, 100, n);
            double start = clock();
            quickSortWorstPivot(arr, 0, n - 1);
            double end = clock();

            midTime += (end - start) / CLOCKS_PER_SEC;
            for (int c = 0; c < n - 1; c++){
                if (arr[c] > arr[c + 1]){
                    cout << endl << "Error: there are unsorted elements!!!" << endl;
                }
            }
            arr.clear();
        }
        cout << " time: " << midTime / k << " sec.";
    }
}

void mergeSortTest(){
    vector <double> arr;

    cout << " Merge sort:" << endl;
    for (int n = 10; n <= 100000; n *= 10){
        cout << endl << n << " elements " << endl;
        double midTime = 0;
        int k = 50;  // count of test arrays
        for (int i = 0; i < k; i++){
            getTestVectorDouble(arr, 100, n);

            double start = clock();
            mergeSort(arr, 0, n - 1);
            double end = clock();

            midTime += (end - start) / CLOCKS_PER_SEC;
            for (int c = 0; c < n - 1; c++){
                if (arr[c] > arr[c + 1]){
                    cout << endl << "Error: there are unsorted elements!!!" << endl;
                }
            }
            arr.clear();
        }
        cout << " time: " << midTime / k << " sec.";
    }

}


void timSortTest(){
    vector <double> arr;

    cout << " Tim sort:" << endl;
    for (int n = 10; n <= 100000; n *= 10){
        cout << endl << n << " elements " << endl;
        double midTime = 0;
        int k = 50;  // count of test arrays
        for (int i = 0; i < k; i++){
            getTestVectorDouble(arr, 100, n+1);

            double start = clock();
            timSort(arr, n);
            double end = clock();

            midTime += (end - start) / CLOCKS_PER_SEC;
            for (int c = 0; c < n - 1; c++){
                if (arr[c] > arr[c + 1]){
                    cout << endl << "Error: there are unsorted elements!!!" << endl;
                }
            }
            arr.clear();
        }
        cout << " time: " << midTime / k << " sec.";
    }
}
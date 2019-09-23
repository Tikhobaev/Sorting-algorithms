//
// Created by Илья on 015 15.09.19.
//
#include "timSort.h"

int binSearch(double val, vector<double>& arr, int start, int end){  // Return an index of the first element, which is above than given(val)
    int left = start, right = end, mid = (end - start)/2;    //Retutn -1 if there aren't
    while (left < right){
        mid = (left + right) / 2;
        if (arr[left] > val)
            return left;
        if (arr[mid] > val)
        {
            if (mid == left + 1)
                return mid;
            else
                right = mid + 1;
        }
        else{
            if (arr[mid] <= val){
                left = mid;
            }
        }
        if ((left + 1) == right){
            left = right;
        }
    }
    return -1;
}

int getMinrun(int n) {
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1; // == n / 2
    }
    return n + r;
}

void insertionSort(vector<double> &arr, int start, int end) {
    for (int i = start + 1; i < end; ++i) {
        double current = arr[i];
        int j = i - 1;
        while ((j >= start) && (current < arr[j])) {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

struct run {
    int start;
    int length;
};

void merge(vector<double> &arr, int fStart, int fLength, int sStart, int sLength) {
    vector<double> tmp;
    for(int i = 0; i < fLength; i++) {
        tmp.push_back(arr[fStart + i]);
    }
    int fIndex = 0;
    int sIndex = sStart;
    int i = fStart;
    int firstStart = fStart;
    int secondStart = sStart;
    int tmpCount = 0, secondCount = 0;
    while (i < sStart + sLength - 1) {
        if (arr[sIndex] > tmp[fIndex]) {
            arr[i] = tmp[fIndex];
            ++fIndex;
            tmpCount++;
            secondCount = 0;
            fIndex = std::min(fIndex, fLength);
        } else if (arr[sIndex] <= tmp[fIndex]) {
            arr[i] = arr[sIndex];
            secondCount++;
            tmpCount = 0;
            ++sIndex;
            sIndex = std::min(sIndex, sStart + sLength);
        }
        if (sIndex == sStart + sLength) {
            if (fIndex != fLength) {
                for (int d = 0; d < fLength - fIndex; d++) {
                    arr[i + 1 + d] = tmp[fIndex + d];
                }
                i = sStart + sLength;
            }
        }
        if (fIndex == fLength) {
            i = sStart + sLength;
        }
        ++i;
    }
}


void timSort(vector<double> &arr, int len) {
//Count minrun
    int minrun = getMinrun(len);

    vector<run> minrunStack;

//divide into runs
    int currentIndex = 0;

    while (currentIndex < len - 1) {
        int currentRunIndex = currentIndex;
        int nextIndex = currentRunIndex + 1;

        if (arr[currentRunIndex] > arr[nextIndex]) {
            swap(arr[currentRunIndex], arr[nextIndex]);
        }

        bool goNext = true;
        while (goNext) {
            if (arr[currentRunIndex] > arr[nextIndex])
                goNext = false;
            if (!(goNext) && (currentRunIndex - currentIndex < minrun))
                goNext = true;
            if (currentRunIndex == len - 1)
                goNext = false;
            if (goNext) {
                currentRunIndex++;
                nextIndex++;
            }
        }
        insertionSort(arr, currentIndex, currentRunIndex + 1);

        run r;
        r.start = currentIndex;
        r.length = currentRunIndex - currentIndex;

        minrunStack.push_back(r);

        currentIndex = currentRunIndex;
    }

//merge runs
    while (minrunStack.size() > 1) {
        run x = minrunStack.at(0);
        minrunStack.erase(minrunStack.begin());
        run y = minrunStack.at(0);
        minrunStack.erase(minrunStack.begin());
        if (x.start > y.start) {
            swap(x.start, y.start);
            swap(x.length, y.length);
        }
        if (y.start != x.start + x.length) {
            minrunStack.push_back(y);
            minrunStack.push_back(x);
            continue;
        }
        merge(arr, x.start, x.length, y.start, y.length);
        x.length = x.length + y.length;
        minrunStack.push_back(x);
    }
}


/*if (tmpCount > 7) {
            int index = binSearch(arr[sIndex], tmp, fIndex, firstStart + fLength - 1);
            if (index == -1) {
                index = fLength - 1 + firstStart - fIndex;
            }
            for (int g = 0; g < index; g++) {
                arr[i] = tmp[fIndex];
                ++fIndex;
                tmpCount++;
                secondCount = 0;
                ++i;
                fIndex = std::min(fIndex, fLength);
            }
        }

        if (secondCount > 7) {
            int index = binSearch(tmp[fIndex], arr, sIndex, secondStart + sLength - 1);
            if (index == -1) {
                index = sLength - 1 + secondStart - sIndex;
            }
            for (int g = 0; g < index; g++) {
                arr[i] = arr[sIndex];
                secondCount++;
                tmpCount = 0;
                ++sIndex;
                ++i;
                sIndex = std::min(sIndex, sStart + sLength);
            }
        }*/

/*void mergeArrays(vector <double> &Arr, long int firstLeft, long int firstLenght, long int secondLeft, long int secondLenght){
    double ArrRes[firstLenght+secondLenght];
    long int firstInd = firstLeft, secondInd = secondLeft;
    bool f = true; // true - first false - second
    int step = 1, iter = 0;//счетчик и шаг для галопа
    for (int i = 0; i < (firstLenght+secondLenght); i ++){
        if ((secondInd >= (secondLeft+secondLenght))||((firstInd < (firstLeft+firstLenght))&&(Arr[firstInd]<Arr[secondInd]))){
            if ((f)&&((secondInd >= (secondLeft+secondLenght))||(firstInd+step < (firstLeft+firstLenght)&&(Arr[firstInd+step]<Arr[secondInd])))){
                for (int j = i; j < i + step; j ++){
                    ArrRes[j] = Arr[firstInd];
                    firstInd++;
                }
                i += step-1;
            }else {
                ArrRes[i] = (Arr[firstInd]);
                firstInd++;
            }
            if (f){
                iter++;
            }else{
                iter = 1;
                step /= 2;
            }
            f = true;
        }else {
            if ((!f)&&((firstInd >= (firstLeft+firstLenght))||(secondInd+step < (secondLeft+secondLenght)&&(Arr[secondInd+step]<Arr[firstInd])))){
                for (int j = i; j < i + step; j ++){
                    ArrRes[j] = Arr[secondInd];
                    secondInd++;
                }
                i += step-1;
            }else {
                ArrRes[i] = (Arr[secondInd]);
                secondInd++;
            }
            if (!f){
                iter++;
            }else{
                iter = 1;
                step /= 2;
            }
            f = false;
        }
        if (iter > 4) {
            iter = 1;
            step *= 2;
        }
        while ((i + step) >= (firstLenght+secondLenght)) step /= 2;
        if (step < 1) step = 1;
    }
    for (int i = 0, ind = firstLeft;i < firstLenght; i ++, ind ++){
        Arr[ind] = ArrRes[i];
    }
    for (int i = firstLenght, ind = secondLeft; i< firstLenght+secondLenght; i ++,ind++){
        Arr[ind] = ArrRes[i];
    }
}*/


/*if (tmpCount > 7) {
    int index = binSearch(arr[sIndex], tmp, fIndex, firstStart + fLength - 1);
    if (index == -1) {
        index = fLength - fIndex;
    }
    else{
        index -= fIndex;
    }
    for (int g = 0; g < index && fIndex < fLength - 1; g++) {
        arr[i] = tmp[fIndex];
        ++fIndex;
        tmpCount++;
        secondCount = 0;
        ++i;
        fIndex = std::min(fIndex, fLength);
    }
}

if (secondCount > 7) {
    int index = binSearch(tmp[fIndex], arr, sIndex, secondStart + sLength - 1);
    if (index == -1) {
        index = sLength + secondStart - sIndex;
    }
    else{
        index -= sIndex;
    }
    for (int g = 0; g < index && sIndex < sLength - 1; g++) {
        arr[i] = arr[sIndex];
        secondCount++;
        tmpCount = 0;
        ++sIndex;
        ++i;
        sIndex = std::min(sIndex, sStart + sLength);
    }
}*/
/*if (tmpCount > 7) {
    int index = binSearch(arr[sIndex], tmp, fIndex, firstStart + fLength - 1);
    if (index == -1) {
        index = fLength - fIndex;
    }
    else{
        index -= fIndex;
    }
    for (int g = 0; g < index && fIndex < fLength - 1; g++) {
        arr[i] = tmp[fIndex];
        ++fIndex;
        tmpCount++;
        secondCount = 0;
        ++i;
        fIndex = std::min(fIndex, fLength);
    }
}

if (secondCount > 7) {
    int index = binSearch(tmp[fIndex], arr, sIndex, secondStart + sLength - 1);
    if (index == -1) {
        index = sLength + secondStart - sIndex;
    }
    else{
        index -= sIndex;
    }
    for (int g = 0; g < index && sIndex < sLength - 1; g++) {
        arr[i] = arr[sIndex];
        secondCount++;
        tmpCount = 0;
        ++sIndex;
        ++i;
        sIndex = std::min(sIndex, sStart + sLength);
    }
}*/
/*if (secondCount > 7){
    for(int gallop_index = sIndex, iter = 1; gallop_index < secondStart + sLength; gallop_index += iter, iter = iter*2){
        if (arr[gallop_index] <= tmp[fIndex]) {
            for(int s = sIndex; s <= gallop_index; s++){
                arr[i] = arr[sIndex];
                secondCount++;
                tmpCount = 0;
                ++sIndex;
                sIndex = std::min(sIndex, sStart + sLength);
            }
        }
        else{
            break;
        }
    }
}
if (tmpCount > 7){
    for(int gallop_index = fIndex, iter = 1; gallop_index < fLength; gallop_index += iter, iter = iter*2){
        if (tmp[gallop_index] < arr[sIndex]) {
            for(int s = fIndex; s <= gallop_index; s++){
                arr[i] = tmp[fIndex];
                tmpCount++;
                secondCount = 0;
                ++fIndex;
                fIndex = std::min(sIndex, sStart + sLength);
            }
        }
        else{
            break;
        }
    }
}*/
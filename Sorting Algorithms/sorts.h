//Ishaan Shete
//December 7th, 2024
//Sorts.h

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <algorithm>
using namespace std;

// BubbleSort
void BubbleSort(vector<int>& arr, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end-i-start; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// InsertionSort
void InsertionSort(vector<int>& arr, int start, int end) {
    for (int i = start+1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// MergeSort merger
void Merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= end) temp[k++] = arr[j++];
    for (int i = 0; i < k; i++) arr[start + i] = temp[i];
}

// MergeSort recursive
void MergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}

// IterativeMergeSort recursive
void IterativeMergeSort(vector<int>& arr, int start, int end) {
    int n = end - start + 1;
    vector<int> temp(n);
    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int mid = min(i + width, n) - 1;
            int right_end = min(i + 2 * width, n) - 1;
            Merge(arr, start + i, start + mid, start + right_end);
        }
    }
}

// QuickSort Partition
int Partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

// QuickSort recursive
void QuickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

// ShellSort
void ShellSort(vector<int>& arr, int start, int end) {
    int n = end - start + 1;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[start + i];
            int j;
            for (j = i; j >= gap && arr[start + j - gap] > temp; j -= gap) {
                arr[start + j] = arr[start + j - gap];
            }
            arr[start + j] = temp;
        }
    }
}

#endif

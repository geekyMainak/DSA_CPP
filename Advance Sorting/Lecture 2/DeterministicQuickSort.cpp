// Median-of-Medians QuickSort (Deterministic QuickSort) ALWAYS T.C. -> O(nlogn)   (for worst case also)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find median of a small group (<= 5 elements)
int findMedian(vector<int>& arr, int start, int n) {
    sort(arr.begin() + start, arr.begin() + start + n);
    return arr[start + n / 2];
}

// Median-of-Medians algorithm to find approximate median in O(n)
int selectPivot(vector<int>& arr, int left, int right) {
    int n = right - left + 1;

    // Step 1: Divide into groups of 5 and find their medians
    vector<int> medians;
    int i;
    for (i = 0; i < n / 5; i++) {
        int median = findMedian(arr, left + i * 5, 5);
        medians.push_back(median);
    }

    // Last group (less than 5 elements)
    if (i * 5 < n) {
        int median = findMedian(arr, left + i * 5, n % 5);
        medians.push_back(median);
    }

    // Step 2: Recursively find the median of medians
    if (medians.size() == 1)
        return medians[0];
    else
        return selectPivot(medians, 0, medians.size() - 1);
}

int partition(vector<int>& arr, int left, int right, int pivot) {
    // Find pivot index
    int pivotIndex = find(arr.begin() + left, arr.begin() + right + 1, pivot) - arr.begin();
    swap(arr[pivotIndex], arr[right]);

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[right]);
    return i;
}

void deterministicQuickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = selectPivot(arr, left, right);
        int pi = partition(arr, left, right, pivot);
        deterministicQuickSort(arr, left, pi - 1);
        deterministicQuickSort(arr, pi + 1, right);
    }
}

int main() {
    vector<int> arr = {5, 6, 1, 9, 3, 8, 4, 10, 13, 22};
    deterministicQuickSort(arr, 0, arr.size() - 1);

    for (int num : arr)
        cout << num << " ";
    return 0;
}

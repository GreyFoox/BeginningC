#include <stdio.h>

void swap(int num[], int i, int j) {
    int temp = num[i];
    num[i] = num[j];
    num[j] = temp;
}

int partition(int arr[], int left, int right) {
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] >= arr[left]) {
            j--;
        }
        while (i < j && arr[i] <= arr[left]) {
            i++;
        }
        swap(arr, i, j);
    }
    swap(arr, i, left);
    return i;
}

void QuickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(arr, left, right);
    QuickSort(arr, left, pivot - 1);
    QuickSort(arr, pivot + 1, right);
}

int main() {
    int arr[] = {10, 45, 89, 47, 36, 51, 23};
    QuickSort(arr, 1, 3);
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
       printf("%d ", arr[i]);
    }
    return 0; // 添加了返回值
}

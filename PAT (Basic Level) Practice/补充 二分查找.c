//
// Created by Administrator on 2025/9/19.
//
#include <stdio.h>
#include <stdbool.h>
// 修改：添加 size 参数
bool BinarySearch(const int arr[], const int size, const int num) {
    /*你将数组作为参数传递给函数时，数组会退化为指向其第一个元素的指针。
     *因此，在函数内部，arr 实际上是一个指针，
     *而不是一个完整的数组。*/
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == num) {
            return true;
        } else if (arr[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]); // 计算数组大小
    // 将结果存储在变量中，避免重复调用函数
    bool result = BinarySearch(arr, size, 7);
    printf("%d", result);
    return 0;
}

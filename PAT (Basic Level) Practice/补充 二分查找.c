//
// Created by Administrator on 2025/9/19.
//
#include <stdio.h>
#include <stdbool.h>
// �޸ģ���� size ����
bool BinarySearch(const int arr[], const int size, const int num) {
    /*�㽫������Ϊ�������ݸ�����ʱ��������˻�Ϊָ�����һ��Ԫ�ص�ָ�롣
     *��ˣ��ں����ڲ���arr ʵ������һ��ָ�룬
     *������һ�����������顣*/
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
    int size = sizeof(arr) / sizeof(arr[0]); // ���������С
    // ������洢�ڱ����У������ظ����ú���
    bool result = BinarySearch(arr, size, 7);
    printf("%d", result);
    return 0;
}

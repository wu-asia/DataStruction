//#include <stdio.h>
//
//// 直接插入排序 升序
//void InsertSort(int arr[], int n)
//{
//    int i, j;
//    // 从第二个数开始，第一个默认有序
//    for (i = 1; i < n; i++)
//    {
//        int temp = arr[i];  // 待插入元素
//        // 向前找位置，比temp大的后移
//        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
//        {
//            arr[j + 1] = arr[j];
//        }
//        arr[j + 1] = temp;  // 插入空位
//    }
//}
//
//// 打印数组
//void PrintArr(int arr[], int n)
//{
//    for (int k = 0; k < n; k++)
//        printf("%d ", arr[k]);
//    printf("\n");
//}
//
//int main()
//{
//    int a[] = { 5, 2, 4, 6, 1, 3 };
//    int len = sizeof(a) / sizeof(a[0]);
//
//    InsertSort(a, len);
//    PrintArr(a, len);
//    return 0;
//}
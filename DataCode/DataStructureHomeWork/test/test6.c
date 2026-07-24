// 折半查找
int BinarySearch(Student stu[], int n, int key){
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (stu[mid].id == key) return mid;
        else if (stu[mid].id < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
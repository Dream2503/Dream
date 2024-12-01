#include <iostream>
#include "14-Sort"

using namespace std;
int main() {
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(array) / sizeof(array[0]);
    Sort<int> sort;
    sort.mergeSort(array, size);
    print(array, size);
    return 0;
}
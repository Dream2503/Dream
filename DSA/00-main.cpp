#include <iostream>
#include "14-Sort"

using namespace std;
int main() {
    int array[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    Sort<int> sort("asc");
    sort.insertionSort(array, 10);
    print(array, 10);
    return 0;
}
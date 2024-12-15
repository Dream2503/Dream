#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array {
    int *list, len, size;
} Array;

Array initialise() {
    Array array;
    printf("Enter the total size of array: ");
    scanf("%d", &array.size);

    array.list = (int*)malloc(array.size*sizeof(int));

    printf("Enter the number of element to initialize: ");
    scanf("%d", &array.len);

    for (int i = 0; i < array.len; i++) {
        printf("Enter %d element: ", i+1);
        scanf("%d", &array.list[i]);
    }
    return array;
}
void display(Array array) {
    printf("\nDisplaying all the elements\n");
    for (int i = 0; i < array.len; i++) printf("%d ", array.list[i]);
    printf("\n");
}
void append(Array *array, int element) {
    if (array->len == array->size - 1) printf("\nInsufficient space in array\n");
    else {
        printf("\nAppending %d to the array\n", element);
        array->list[array->len] = element;
        array->len++;
    }
}
void insert(Array *array, int index, int element) {
    if (array->len == array->size - 1) printf("\nInsufficient space in array\n");
    else if (index > array->len) printf("\nIndex out of range\n");
    else {
        printf("\nInserting %d in %d index\n", element, index);
        for (int i = array->len; i > index; i--)  array->list[i] = array->list[i-1];
        array->list[index] = element;
        array->len++;
    }
}
int delete(Array *array, int index) {
    if (index >= array->len) {
        printf("\nIndex out of bound\n");
        return 0;
    } else {
        int element = array->list[index];
        for (int i = index; i < array->len - 1; i++) array->list[i] = array->list[i+1];
        array->len--;
        return element;
    }
}
int search(Array array, int key) {
    for (int i = 0; i < array.len; i++) if (array.list[i] == key) return i;
    return -1;
}
int get(Array array, int index) {
    if (index >= array.len || index < 0) {
        printf("\nIndex out of bound\n");
        return -1;
    }
    return array.list[index];
}
void set(Array *array, int index, int value) {
    if (index >= array->len || index < 0) {
        printf("\nIndex out of bound\n");
        return;
    }
    array->list[index] = value;
}
int max(Array array) {
    int max = array.list[0];
    for (int i = 1; i < array.len; i++) if (array.list[i] > max) max = array.list[i];
    return max;
}
int min(Array array) {
    int min = array.list[0];
    for (int i = 1; i < array.len; i++) if (array.list[i] > min) min = array.list[i];
    return min;
}
int sum(Array array) {
    int sum = 0;
    for (int i = 0; i < array.len; i++) sum += array.list[i];
    return sum;
}
double average(Array array) {return sum(array) / (double)array.len;}
void swap(int *element1, int *element2) {
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}
void reverse(Array *array) {
    int temp, i, j;
    for (i = 0, j = array->len - 1; i < j; i++, j--) swap(&array->list[i], &array->list[j]);
}
int binarySearch(Array array, int key) {
    int low = 0, mid, high = array.len - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (array.list[mid] == key) return mid;
        else if (array.list[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
void leftShift(Array *array) {
    delete(array, 0);
    array->list[array->len-1] = 0;
    array->len++;
}
void rightShift(Array *array) {
    insert(array, 0, 0);
    array->len--;
}
void leftRotate(Array *array) {
    int temp = array->list[0];
    delete(array, 0);
    array->list[array->len-1] = temp;
}
void rightRotate(Array *array) {
    int temp = array->list[array->len-1];
    insert(array, 0, temp);
}
void insertSort(Array *array, int element) {
    if (array->len == array->size - 1) printf("\nInsufficient space in array\n");
    else {
        int i = array->len - 1;

        while (array->list[i] > element) {
            array->list[i+1] = array->list[i];
            i--;
        }
        array->list[i+1] = element;
        array->len++;
    }
}
bool isSorted(Array array) {
    for (int i = 1; i < array.len; i++) if (array.list[i] < array.list[i-1]) return false;
    return true;
}
void rearrangePosNeg(Array *array) {
    int i = 0, j = array->len - 1;
    
    while (i < j) {
        while (array->list[i] < 0) i++;
        while (array->list[j] >= 0) j--;
        if (i < j) swap(&array->list[i], &array->list[j]);
    }
}
Array mergeSorted(Array array1, Array array2) {
    int i = 0, j = 0, k = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length*sizeof(int)), length, length};

    while (i != array1.len && j != array2.len) {
        if (array1.list[i] < array2.list[j]) result.list[k++] = array1.list[i++];
        else if (array1.list[i] > array2.list[j]) result.list[k++] = array2.list[j++];
        else {
            result.list[k++] = array1.list[i++];
            result.list[k++] = array2.list[j++];
        }
    }
    for (; i < array1.len; i++) result.list[k++] = array1.list[i];
    for (; j < array2.len; j++) result.list[k++] = array2.list[j];
    return result;
}
void mergeAppend(Array *array1, Array array2) {
    int length = array1->len + array2.len;
    if (array1->size < length) printf("\nInsufficient space in array\n");
    else {
        for (int i = array1->len, j = 0; i < length; i++, j++) array1->list[i] = array2.list[j];
        array1->len = length;
    }
}
Array mergeConcat(Array array1, Array array2) {
    int k = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length*sizeof(int)), length, length};
    for (int i = 0; i < array1.len; i++) result.list[k++] = array1.list[i];
    for (int j = 0; j < array2.len; j++) result.list[k++] = array1.list[j];
    return result;
}
bool mergeCompare(Array array1, Array array2) {
   if (array1.len != array2.len) return false;
   for (int i = 0; i < array1.len; i++) if (array1.list[i] != array2.list[i]) return false;
   return true; 
}
void mergeCopy(Array array1, Array *array2) {
    if (array2->size < array1.len) printf("\nInsufficient space for the array\n");
    else {
        for (int i = 0; i < array1.len; i++) array2->list[i] = array1.list[i];
        array2->len = array1.len;
    }
}
Array setUnion(Array array1, Array array2) {
    int length = array1.len + array2.len;
    bool flag = true;
    Array result = {(int*)malloc(length*sizeof(int)), 0, length};
    for (int i = 0; i < array1.len; i++) result.list[i] = array1.list[i];
    result.len = array1.len;

    for (int i = 0; i < array2.len; i++) {
        for (int j = 0; j < result.len; j++) {
            if (array2.list[i] == result.list[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            append(&result, array2.list[i]);

        flag = true;
    }
    return result;
}
Array setIntersection(Array array1, Array array2) {
    int length = array1.len + array2.len;
    Array result = {(int*)malloc(length*sizeof(int)), 0, length};

    for (int i = 0; i < array1.len; i++) {
        for (int j = 0; j < array2.len; j++) {
            if (array1.list[i] == array2.list[j])
                append(&result, array1.list[i]);
        }
    }
    return result;
}
Array setDifference(Array array1, Array array2) {
    int length = array1.len + array2.len;
    bool flag = true;
    Array result = {(int*)malloc(length*sizeof(int)), 0, length};

    for (int i = 0; i < array1.len; i++) {
        for (int j = 0; j < array2.len; j++) {
            if (array1.list[i] == array2.list[j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            append(&result, array1.list[i]);
        
        flag = true;
    }
    return result;
}
bool setMembership(Array array, int element) {
    if (search(array, element) == -1)
        return false;
    return true;
}
Array sortedSetUnion(Array array1, Array array2) {
    int i = 0, j = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length*sizeof(int)), 0, length};

    while (i < array1.len && j < array2.len) {
        if (array1.list[i] < array2.list[j]) append(&result, array1.list[i++]);
        else if (array1.list[i] > array2.list[j]) append(&result, array2.list[j++]);
        else {
            append(&result, array1.list[i++]);
            j++;
        }
    }
    for (; i < array1.len; i++) append(&result, array1.list[i]);
    for (; j < array2.len; j++) append(&result, array2.list[j]);
    return result;
}
Array sortedSetIntersection(Array array1, Array array2) {
    int i = 0, j = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length*sizeof(int)), 0, length};

    while (i < array1.len && j < array2.len) {
        if (array1.list[i] < array2.list[j]) i++;
        else if (array1.list[i] > array2.list[j]) j++;
        else {
            append(&result, array1.list[i++]);
            j++;
        }
    }
    return result;
}
Array sortedSetDifference(Array array1, Array array2) {
    int i = 0, j = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length*sizeof(int)), 0, length};

    while (i < array1.len && j < array2.len) {
        if (array1.list[i] < array2.list[j]) append(&result, array1.list[i++]);
        else if (array1.list[i] > array2.list[j]) append(&result, array2.list[j++]);
        else {i++; j++;}
    }
    for (; i < array1.len; i++) append(&result, array1.list[i]);
    for (; j < array2.len; j++) append(&result, array2.list[j]);
    return result;
}
bool sortedSetMembership(Array array, int element) {
    if (binarySearch(array, element) == -1)
        return false;
    return true;
}

int main() {
    int array1[] = {3, 4, 5, 6, 10};
    int array2[] = {2, 4, 5, 7, 12};
    Array list1 = {array1, 5, 5};
    Array list2 = {array2, 5, 5};
    display(sortedSetDifference(list1, list2));
    return 0;
}
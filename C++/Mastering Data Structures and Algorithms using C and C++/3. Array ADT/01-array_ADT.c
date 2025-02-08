#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int *list, len, size;
} Array;

Array initialise() {
    Array array;
    int i;

    printf("Enter the total size of array: ");
    scanf("%d", &array.size);
    array.list = (int*)malloc(array.size * sizeof(int));

    printf("Enter the number of element to initialize: ");
    scanf("%d", &array.len);

    for (i = 0; i < array.len; i++) {
        printf("Enter %d element: ", i+1);
        scanf("%d", &array.list[i]);
    }
    return array;
}

void display(Array array) {
    int i;
    printf("\nDisplaying all the elements\n");

    for (i = 0; i < array.len; i++) {
        printf("%d ", array.list[i]);
    }
    printf("\n");
}

void append(Array *array, int element) {
    if (array->len == array->size) {
        printf("\nInsufficient space in array\n");
    } else {
        printf("\nAppending %d to the array\n", element);
        array->list[array->len] = element;
        array->len++;
    }
}

void insert(Array *array, int index, int element) {
    int i;

    if (array->len == array->size) {
        printf("\nInsufficient space in array\n");
    } else if (index > array->len) {
        printf("\nIndex out of range\n");
    } else {
        printf("\nInserting %d in %d index\n", element, index);

        for (i = array->len; i > index; i--) {
            array->list[i] = array->list[i - 1];
        }
        array->list[index] = element;
        array->len++;
    }
}

int delete(Array *array, int index) {
    if (index >= array->len) {
        printf("\nIndex out of range\n");
        return -1;
    } else {
        int element = array->list[index], i;

        for (i = index; i < array->len - 1; i++) {
            array->list[i] = array->list[i + 1];
        }
        array->len--;
        return element;
    }
}

int search(Array array, int key) {
    int i;

    for (i = 0; i < array.len; i++) {
        if (array.list[i] == key) {
            return i;
        }
    }
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
    int res = array.list[0], i;

    for (i = 1; i < array.len; i++) {
        if (array.list[i] > res) {
            res = array.list[i];
        }
    }
    return res;
}

int min(Array array) {
    int res = array.list[0], i;

    for (i = 1; i < array.len; i++) {
        if (array.list[i] > res) {
            res = array.list[i];
        }
    }
    return res;
}

int sum(Array array) {
    int res = 0, i;

    for (i = 0; i < array.len; i++) {
        res += array.list[i];
    }
    return res;
}

double average(Array array) {
    return sum(array) / (double)array.len;
}

void swap(int *element1, int *element2) {
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

void reverse(Array *array) {
    int temp, i, j;

    for (i = 0, j = array->len - 1; i < j; i++, j--) {
        swap(&array->list[i], &array->list[j]);
    }
}

int binary_search(Array array, int key) {
    int low = 0, mid, high = array.len - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (array.list[mid] == key) {
            return mid;
        } else if (array.list[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void left_shift(Array *array) {
    delete(array, 0);
    array->list[array->len - 1] = 0;
    array->len++;
}

void right_shift(Array *array) {
    insert(array, 0, 0);
    array->len--;
}

void left_rotate(Array *array) {
    int temp = array->list[0];
    delete(array, 0);
    array->list[array->len - 1] = temp;
}

void right_rotate(Array *array) {
    int temp = array->list[array->len - 1];
    insert(array, 0, temp);
}

void insert_sort(Array *array, int element) {
    if (array->len == array->size) {
        printf("\nInsufficient space in array\n");
    } else {
        int i = array->len - 1;

        while (array->list[i] > element) {
            array->list[i + 1] = array->list[i];
            i--;
        }
        array->list[i + 1] = element;
        array->len++;
    }
}

int is_sorted(Array array) {
    int i;

    for (i = 1; i < array.len; i++) {
        if (array.list[i] < array.list[i-1]) {
            return 0;
        }
    }
    return 1;
}

void rearrange_pos_neg(Array *array) {
    int i = 0, j = array->len - 1;
    
    while (i < j) {
        while (array->list[i] < 0) {
            i++;
        }
        while (array->list[j] >= 0) {
            j--;
        }
        if (i < j) {
            swap(&array->list[i], &array->list[j]);
        }
    }
}

Array merge_sorted(Array array1, Array array2) {
    int i = 0, j = 0, k = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length * sizeof(int)), length, length};

    while (i != array1.len && j != array2.len) {
        if (array1.list[i] < array2.list[j]) {
            result.list[k] = array1.list[i];
            i++;
        } else {
            result.list[k] = array2.list[j];
            j++;
        }
        k++;
    }
    while (i < array1.len) {
        result.list[k] = array1.list[i];
        k++, i++;
    }
    while (j < array2.len) {
        result.list[k] = array2.list[j];
        k++, j++;
    }
    return result;
}

void merge_append(Array *array1, Array array2) {
    int length = array1->len + array2.len, i, j;

    if (array1->size < length) {
        printf("\nInsufficient space in array\n");
    } else {
        for (i = array1->len, j = 0; j < array2.len; i++, j++) {
            array1->list[i] = array2.list[j];
        }
        array1->len = length;
    }
}

Array merge_concat(Array array1, Array array2) {
    int k = 0, length = array1.len + array2.len, i;
    Array result = {(int*)malloc(length * sizeof(int)), length, length};

    for (i = 0; i < array1.len; i++) {
        result.list[k++] = array1.list[i];
    }
    for (i = 0; i < array2.len; i++) {
        result.list[k++] = array2.list[i];
    }
    return result;
}

int merge_compare(Array array1, Array array2) {
    int i;

    if (array1.len != array2.len) {
        return 0;
    }
    for (i = 0; i < array1.len; i++) {
        if (array1.list[i] != array2.list[i]) {
            return 0;
        }
    }
    return 1; 
}

void merge_copy(Array array1, Array *array2) {
    int i;

    if (array2->size < array1.len) {
        printf("\nInsufficient space for the array\n");
    } else {
        for (i = 0; i < array1.len; i++) {
            array2->list[i] = array1.list[i];
        }
        array2->len = array1.len;
    }
}

Array set_union(Array array1, Array array2) {
    int length = array1.len + array2.len, flag = 1, i, j;
    Array result = {(int*)malloc(length * sizeof(int)), 0, length};

    for (i = 0; i < array1.len; i++) {
        result.list[i] = array1.list[i];
    }
    result.len = array1.len;

    for (i = 0; i < array2.len; i++) {
        for (j = 0; j < result.len; j++) {
            if (array2.list[i] == result.list[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            append(&result, array2.list[i]);
        }

        flag = 1;
    }
    return result;
}

Array set_intersection(Array array1, Array array2) {
    int length = array1.len + array2.len, i, j;
    Array result = {(int*)malloc(length * sizeof(int)), 0, length};

    for (i = 0; i < array1.len; i++) {
        for (j = 0; j < array2.len; j++) {
            if (array1.list[i] == array2.list[j]) {
                append(&result, array1.list[i]);
            }
        }
    }
    return result;
}

Array set_difference(Array array1, Array array2) {
    int length = array1.len + array2.len, flag = 1, i, j;
    Array result = {(int*)malloc(length * sizeof(int)), 0, length};

    for (i = 0; i < array1.len; i++) {
        for (j = 0; j < array2.len; j++) {
            if (array1.list[i] == array2.list[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            append(&result, array1.list[i]);
        }
        
        flag = 1;
    }
    return result;
}

int set_membership(Array array, int element) {
    if (search(array, element) == -1) {
        return 0;
    }
    return 1;
}

Array sorted_set_union(Array array1, Array array2) {
    int i = 0, j = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length * sizeof(int)), 0, length};

    while (i < array1.len && j < array2.len) {
        if (array1.list[i] < array2.list[j]) {
            append(&result, array1.list[i++]);
        } else if (array1.list[i] > array2.list[j]) {
            append(&result, array2.list[j++]);
        } else {
            append(&result, array1.list[i++]);
            j++;
        }
    }
    for (; i < array1.len; i++) {
        append(&result, array1.list[i]);
    }
    for (; j < array2.len; j++) {
        append(&result, array2.list[j]);
    }
    return result;
}

Array sorted_set_intersection(Array array1, Array array2) {
    int i = 0, j = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length * sizeof(int)), 0, length};

    while (i < array1.len && j < array2.len) {
        if (array1.list[i] < array2.list[j]) {
            i++;
        } else if (array1.list[i] > array2.list[j]) {
            j++;
        } else {
            append(&result, array1.list[i++]);
            j++;
        }
    }
    return result;
}

Array sorted_set_difference(Array array1, Array array2) {
    int i = 0, j = 0, length = array1.len + array2.len;
    Array result = {(int*)malloc(length * sizeof(int)), 0, length};

    while (i < array1.len && j < array2.len) {
        if (array1.list[i] < array2.list[j]) {
            append(&result, array1.list[i++]);
        } else if (array1.list[i] > array2.list[j]) {
            append(&result, array2.list[j++]);
        } else {
            i++, j++;
        }
    }
    for (; i < array1.len; i++) {
        append(&result, array1.list[i]);
    }
    for (; j < array2.len; j++) {
        append(&result, array2.list[j]);
    }
    return result;
}

int sorted_set_membership(Array array, int element) {
    if (binary_search(array, element) == -1) {
        return 0;
    }
    return 1;
}

int main() {
    int array1[] = {3, 4, 5, 6, 10};
    int array2[] = {2, 4, 5, 7, 12};
    Array list1 = {array1, 5, 5};
    Array list2 = {array2, 5, 5};
    display(sorted_set_difference(list1, list2));
    return 0;
}
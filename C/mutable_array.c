#include<stdio.h>
#include<stdlib.h>
#include<complex.h>

//先定义数组结构体
typedef struct 
{
    double complex *data;
    int capacity;
    int size; 
}dynamicarray;

//初始化
void initarray(dynamicarray *arr,int initialcapacity)
{
    arr->data = (double complex *)malloc(initialcapacity * sizeof(double complex));
    arr->size = 0;
    arr->capacity = initialcapacity;
}

//释放空间
void freearray(dynamicarray *arr)
{
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

//扩容
void resizeArray(dynamicarray *arr, int newCapacity) {
    arr->data = (double complex *)realloc(arr->data, newCapacity * sizeof(double complex));
    arr->capacity = newCapacity;
}

//push函数
void push(dynamicarray *arr, double complex value) {
    if (arr->size >= arr->capacity) {
        resizeArray(arr, arr->capacity * 2);  
    }
    arr->data[arr->size++] = value;
}

//insert函数
void insert(dynamicarray *arr, int index, double complex value) {
    if (index < 0 || index > arr->size) {
        printf("Index out of bounds error.\n");
        return;
    }
    if (arr->size >= arr->capacity) {
        resizeArray(arr, arr->capacity * 2); 
    }
    for (int i = arr->size; i > index; --i) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->size++;
}

//delete函数
void delete(dynamicarray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds error.\n");
        return;
    }
    for (int i = index; i < arr->size - 1; ++i) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

//获取元素
double complex get(dynamicarray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds error.\n");
        exit(EXIT_FAILURE);
    }
    return arr->data[index];
}

// 设置指定位置的元素
void set(dynamicarray *arr, int index, double complex value) {
    if (index < 0 || index >= arr->size) {
        printf("Index out of bounds error.\n");
        return;
    }
    arr->data[index] = value;
}

//查找元素
int find(dynamicarray *arr, double complex value) {
    for (int i = 0; i < arr->size; ++i) {
        if (arr->data[i] == value) {
            return i;
        }
    }
    return -1;
}

// 获取数组的长度
int len(dynamicarray *arr) {
    return arr->size;
}


int main() {
    dynamicarray arr;
    initarray(&arr, 4); 
    
    push(&arr, 1.0 + 2.0 * I);
    push(&arr, 3.0 + 4.0 * I);
    push(&arr, 5.0 + 6.0 * I);
    insert(&arr, 1, 7.0 + 8.0 * I);

    //打印
    for (int i = 0; i < len(&arr); ++i) {
        printf("Element at index %d: %.2f + %.2fi\n", i, creal(get(&arr, i)), cimag(get(&arr, i)));
    }

    // 删除
    delete(&arr, 2);
    printf("Array length after deleted: %d\n", len(&arr));

    // 查找
    int index = find(&arr, 3.0 + 4.0 * I);
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found.\n");
    }

    // 释放
    freearray(&arr);

    return 0;
}
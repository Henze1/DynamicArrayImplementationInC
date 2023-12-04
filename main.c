#include <stdio.h>
#include <stdlib.h>

int* create();
int* RealLoc(int*);
void print(int*, int*);
void delete(int*);
void pushBack(int*, int*, int);
void Remove(int*, int);
void operation(int*);

int size = 0;
int capacity = 5;
int num = 0;


int main() {
    int* arr = create(capacity);
    operation(arr);

}

void operation(int* arr) {
    printf("Choose an option\n");
    printf("1. Pushback an element.\n2. Print the array.\n3. remove an element.\n4. Exit.\n");
    int option =0;
    do {
        scanf("%d", &option);
    } while (option < 1 || option > 4);
    if (option == 1) {
        printf("Enter a number to add in array:");
        scanf("%d", &num);
        pushBack(arr, &size, num);
    } else if (option == 2) {
        print(arr, &size);
    } else if (option == 3){
        int remnum = 0;
        printf("Enter a number to remove from array:");
        scanf("%d", &remnum);
        Remove(arr, remnum);
    } else {
        delete(arr);
        return;
    }
    operation(arr);
}

int* create() {
    int* arr = (int*)calloc(5, sizeof(int));
    return arr;
}

int* RealLoc(int* arr) {
    capacity *= 2;
    int* arr1 = realloc(arr, capacity);
    arr = arr1;

    return arr;
}

void pushBack(int* arr, int* len, int num) {
    if (*len == sizeof(arr)) {
        arr = RealLoc(arr);
    }

    *(arr + *len) = num;
    ++*(len);
}

void Remove(int* arr, int num) {
    int ind = -1;
    for (int i = 0; i < size; ++i) {
        if (num == *(arr + i)) {
            printf("%d is being removed\n", num);
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        printf("The array doesn't contain entered number:\m");
        return;
    } else {
        for (int i = ind; i < size; ++i) {
            *(arr + i) = *(arr + i + 1);
        }
        --size;
    }
}

void delete(int* arr) {
    free(arr);
    arr = NULL;
}

void print(int* arr, int* len) {
    for (int i = 0; i < *len; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
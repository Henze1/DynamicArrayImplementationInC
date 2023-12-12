#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {int* vec; int size; int capacity;} Vector;

int at(const Vector*, int);
bool empty(const Vector*);
void PushBack(Vector*, int);
void PopBack(Vector*);
int front(const Vector*);
int back(const Vector*);
int size(const Vector*);
int capacity(const Vector*);
void Display(const Vector*);
void insert(Vector*, int, int);
void erase(Vector*, int);
void clear(Vector*);
void shrink_to_fit(Vector*);
void initializeVector(Vector*, int);
void destroyVector(Vector*);
void resize(Vector*);

int main() {
    Vector vector;
    vector.capacity = 1;
    vector.size = 0;
    initializeVector(&vector, vector.capacity);
    int option;
    do {
        printf("Choose an option:\n");
        printf("1. PushBack an element\n");
        printf("2. PopBack an element\n");
        printf("3. Show the first element\n");
        printf("4. Show the last element\n");
        printf("5. Show the element at position\n");
        printf("6. Display the vector\n");
        printf("7. Show the count of elements\n");
        printf("8. Show the capacity of the vector\n");
        printf("9. Insert an element\n");
        printf("10. Erase an element\n");
        printf("11. Clear the vector\n");
        printf("12. Clear the free space in vector\n");
        printf("13. Exit\n");
        do {
            scanf("%d", &option);
        } while (option < 1 || option > 13);

        int num;
        int pos;
        switch (option) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                PushBack(&vector, num);
                break;
            case 2:
                printf("Popped: %d\n", vector.vec[vector.size - 1]);
                PopBack(&vector);
                break;
            case 3:
                printf("First element: %d\n", front(&vector));
                break;
            case 4:
                printf("Last element: %d\n", back(&vector));
                break;
            case 5:
                printf("Enter a position: ");
                scanf("%d", &pos);
                printf("Element at position %d: %d\n", pos, at(&vector, 0));
                break;
            case 6:
                printf("Vector...\n");
                Display(&vector);
            case 7:
                printf("Size: %d\n", size(&vector));
                break;
            case 8:
                printf("Capacity: %d\n", capacity(&vector));
                break;
            case 9:
                printf("Enter a position: ");
                scanf("%d", &pos);
                printf("Enter a number: ");
                scanf("%d", &num);
                insert(&vector, pos, num);
                break;
            case 10:
                printf("Enter a position to erase: ");
                scanf("%d", &pos);
                erase(&vector, pos);
                break;
            case 11:
                printf("Cleared!\n");
                clear(&vector);
                break;
            case 12:
                printf("Shrunk!\n");
                shrink_to_fit(&vector);
                break;

        }
    } while (option != 13);

    destroyVector(&vector);
    return 0;
}

int at(const Vector* vector, int pos) {
    if (pos < vector->size && pos >= 0) {
        return *(vector->vec + pos);
    }
    printf("The position is empty or smaller than 0!\n");
    return 0;
}

bool empty(const Vector* vector) {
    if (vector->size == 0) {
        return true;
    }
    return false;
}

void PushBack(Vector* vector, int value) {
    if (vector->size == vector->capacity) {
        resize(vector);
    }
    *(vector->vec + vector->size) = value;
    vector->size++;
}

void PopBack(Vector* vector) {
    if (vector->size == 0) {
        printf("The vector is empty!\n");
        return;
    }
    *(vector->vec + vector->size - 1) = 0;
    --vector->size;
}

int front(const Vector* vector) {
    if (!empty(vector)) {
        return *(vector->vec);
    }
    printf("The vector is empty");
    return 0;
}

int back(const Vector* vector) {
    if (empty(vector)) {
        return *(vector->vec + vector->size - 1);
    }
    printf("The vector is empty");
    return 0;
}

void Display(const Vector* vector) {
    for (int i = 0; i < vector->size; ++i) {
        printf("vec[%d] = %d ", i, *(vector->vec + i));
        printf("\n");
    }
}

int size(const Vector* vector) {
    return vector->size;
}

int capacity(const Vector* vector) {
    return vector->capacity;
}

void insert(Vector* vector, int pos, int value) {
    if (pos < vector->size) {
        *(vector->vec + pos) = value;
    }
    else {
        printf("The position is not available!\n");
    }
}

void erase(Vector* vector, int pos) {
    if (pos < vector->size) {
        *(vector->vec + pos) = 0;
        for (int i = pos; i < vector->size; ++i) {
            *(vector->vec + i) = *(vector->vec + i + 1);
        }
        --vector->size;
    } else {
        printf("The position is not available!\n");
    }
}

void clear(Vector* vector) {
    for (int i = 0; i < vector->size; ++i) {
        vector->vec[i] = 0;
    }
    vector->size = 0;
    vector->vec = realloc(vector->vec, vector->capacity);
    vector->vec[0] = 0;
}

void shrink_to_fit(Vector* vector) {
    vector->capacity = vector->size;
    vector->vec = realloc(vector->vec, vector->capacity);
}

void initializeVector(Vector* vector, int initialCapacity) {
    vector->vec = malloc(initialCapacity * sizeof(int));
}

void destroyVector(Vector* vector) {
    free(vector->vec);
    vector->vec = NULL;
}

void resize(Vector* vector) {
    vector->capacity *= 2;
    if (vector->capacity > 100) {
        vector->capacity = 100;
        printf("You are on maximum capacity and can't grow more than 100!\n");
    }
    vector->vec = realloc(vector->vec, vector->capacity);
}
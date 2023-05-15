#include "stdio.h"
#include <stdlib.h>

struct Vector {
    int* array;
    size_t cursor;
    size_t capacity;
};

struct Vector* new_vector(size_t capacity) {
    struct Vector* vector = malloc(sizeof(struct Vector));
    vector->array = (int*)malloc(sizeof(int) * capacity);
    vector->capacity = capacity;
    vector->cursor = 0;
    return vector;
}

void append(struct Vector* vector, int value) {
    if (vector->cursor >= vector->capacity) {
        vector->capacity *= 2;
        vector->array = realloc(vector->array, sizeof(int) * vector->capacity);
    }
    vector->array[vector->cursor] = value;
    vector->cursor++;
}

int main() {
    size_t initial_vector_capacity = 2;
    struct Vector* vector = new_vector(initial_vector_capacity);
    append(vector, 10);
    append(vector, 20);
    append(vector, 30);
    append(vector, 40);
    append(vector, 50);

    for (int i = 0; i < vector->capacity; i++) {
        printf("%d\n", vector->array[i]);
    }
    free(vector);
    return 0;
}
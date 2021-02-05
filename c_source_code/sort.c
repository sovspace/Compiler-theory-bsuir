#import <stdio.h>
#import <stdlib.h>

void swap_float(float *lhs, float *rhs) {
    float temp = *rhs;
    *rhs = *lhs;
    *lhs = temp;
}

size_t partition_float_array(float *array, size_t left, size_t right) {
    float pivot = array[(right - left) / 2 + left];
    size_t i = left;
    size_t j = right;
    while (1) {
        while (array[i] < pivot) {
            i += 1;
        }
        while (array[j] > pivot) {
            j -= 1;
        }
        if (i >= j) {
            return j;
        }
        swap_float(&array[i], &array[j]);
    }
}

void sort_float_array(float *array, size_t left, size_t right) {
    if (left < right) {
        size_t partition = partition_float_array(array, left, right);
        sort_float_array(array, left, partition);
        sort_float_array(array, partition + 1, right);
    }
}

void read_array(float *array, size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        scanf("%f", &array[i]);
    }
}

void print_array(float *array, size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        printf("%f ", array[i]);
    }
}

int main() {
    printf("%s", "Input array size\n");
    size_t array_size;
    scanf("%lu", &array_size);

    printf("%s", "Input array\n");
    float *array = malloc(sizeof(float ) * array_size);
    read_array(array, array_size);

    sort_float_array(array, 0, array_size - 1);

    printf("%s", "Printed array\n");
    print_array(array, array_size);

    free(array);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>


int reduce_int_array(int* array, size_t array_size, int(*reduced_function)(int, int), int initial_value) {
    int result = initial_value;
    for (size_t i = 0; i < array_size; i++) {
        result = reduced_function(result, array[i]);
    }
    return result;
}

int mul(int lhs, int rhs) {
    return lhs * rhs;
}

int add(int lhs, int rhs) {
    return lhs + rhs;
}


void read_array(int* array, size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        scanf("%d", &array[i]);
    }
}


int main()
{
    printf("%s", "Input array size\n");
    size_t array_size;
    scanf("%lu", &array_size);

    printf("%s", "Input array\n");
    int* array = malloc(sizeof(int) * array_size);
    read_array(array, array_size);

    int reduce_mul_result = reduce_int_array(array, array_size, mul, 1);
    printf("%s%d%s", "Mul reduce result ", reduce_mul_result, "\n");

    int reduce_add_result = reduce_int_array(array, array_size, add, 0);
    printf("%s%d%s", "Add reduce result ", reduce_add_result, "\n");
    free(array);
    return 0;
}

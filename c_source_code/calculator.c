#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const size_t BUFF_SIZE = 256;
enum Operation {Addition, Subtraction, Multiplication, Division, Error};


enum Operation get_operation(char* operation_string) {
    if (!strcmp(operation_string, "add") || !strcmp(operation_string, "+")) {
        return Addition;
    } else if (!strcmp(operation_string, "sub") || !strcmp(operation_string, "-")) {
        return Subtraction;
    } else if (!strcmp(operation_string, "mul") || !strcmp(operation_string, "*")) {
        return Multiplication;
    } else if (!strcmp(operation_string, "div") || !strcmp(operation_string, "/")) {
        return Division;
    } else {
        return Error;
    }
}

double compute(double lhs, double rhs, enum Operation operation) {
    double result = 0.0;
    switch (operation) {
        case Addition:
            result = lhs + rhs;
            break;
        case Subtraction:
            result = lhs - rhs;
            break;
        case Multiplication:
            result = lhs * rhs;
            break;
        case Division:
            if (rhs != 0.0) {
                result = lhs / rhs;
            } else {
                fprintf(stderr, "Wrong division");
                result = 0.0;
            }
            break;
        case Error:
            fprintf(stderr, "Wrong operation");
    }
    return result;
}


int main() {
    char* operation_string = malloc(sizeof(char) * BUFF_SIZE);
    printf("%s", "Input operation:\n");
    scanf("%s", operation_string);

    double lhs, rhs;
    printf("%s", "Input arguments:\n");
    scanf("%lf%lf", &lhs, &rhs);

    double operation_result = compute(lhs, rhs, get_operation(operation_string));
    printf("%s%lf", "Operation result: ", operation_result);

    return 0;
}
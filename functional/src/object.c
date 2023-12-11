#include "error.h"
#include <math.h>
#include <object.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Object pipeObject;

Object newObject(Class class, void* value) {
    return (Object){value, class};
}

NextObject startPipe(Object a) {
    pipeObject = newObject(a.class, a.value);
    nextObject;
}

Object endPipe() {
    return pipeObject;
}

void* getValue() {
    return pipeObject.value;
}

Class getClass() {
    return pipeObject.class;
}

NextObject toFloat() {
    switch (pipeObject.class) {
        case INT: {
            float temp = (float) *(int *) pipeObject.value;
            pipeObject.value = &temp;
            break;
        }
        case FLOAT:
            break;
        case DOUBLE: {
            float temp = (float) *(double *) pipeObject.value;
            pipeObject.value = &temp;
            break;
        }
        case CHAR: {
            if (*(char *) pipeObject.value < '0'
                || *(char *) pipeObject.value > '9') {
                exit(NAN_VALUE);
            }
            float temp = (float) (*(char *) pipeObject.value - '0');
            pipeObject.value = &temp;
            break;
        }
        case STRING:
            //pipeObject.value = (float) *(char*) pipeObject.value;
            break;
        default:
            exit(NAN_CLASS);
    }
    pipeObject.class = FLOAT;
    nextObject;
}

NextObject toDouble() {
    switch (pipeObject.class) {
        case INT: {
            double temp = (double) *(int *) pipeObject.value;
            pipeObject.value = &temp;
            break;
        }
        case FLOAT: {
            double temp = (double) *(float *) pipeObject.value;
            pipeObject.value = &temp;
            break;
        }
        case DOUBLE:
            break;
        case CHAR: {
            if (*(char *) pipeObject.value < '0'
                || *(char *) pipeObject.value > '9') {
                exit(NAN_VALUE);
            }
            double temp = (double) (*(char *) pipeObject.value - '0');
            pipeObject.value = &temp;
            break;
        }
        case STRING:
            //pipeObject.value = (double) *(char*) pipeObject.value;
            break;
        default:
            exit(NAN_CLASS);
    }
    pipeObject.class = DOUBLE;
    nextObject;
}

NextObject toInt() {
    switch (pipeObject.class) {
        case INT:
            break;
        case FLOAT: {
            int temp = (int) *(float *) pipeObject.value;
            pipeObject.value = &temp;
            break;
        }
        case DOUBLE: {
            int temp = (int) *(double *) pipeObject.value;
            pipeObject.value = &temp;
            break;
        }
        case CHAR: {
            if (*(char *) pipeObject.value < '0'
                || *(char *) pipeObject.value > '9') {
                exit(NAN_VALUE);
            }
            int temp = (int) (*(char *) pipeObject.value - '0');
            pipeObject.value = &temp;
            break;
        }
        case STRING:
            //pipeObject.value = (int) *(char*) pipeObject.value;
            break;
        default:
            exit(NAN_CLASS);
    }
    pipeObject.class = INT;
    nextObject;
}

bool chrii(char c) {
    return c >= '0' && c <= '9';
}

bool strii(char* str) {
    char *endptr;
    strtoll(str, &endptr, 10);

    // Check if the conversion was successful
    return (*endptr == '\0' || *endptr == '\n');
}

bool strif(char* str) {
    char *endptr;
    strtod(str, &endptr);

    // Check if the conversion was successful
    return (*endptr == '\0' || *endptr == '\n');
}

NextObject add(Object a) {
    switch (pipeObject.class) {
        case INT: {
            switch (a.class) {
                case INT: {
                    int temp = *(int *) pipeObject.value + *(int *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = INT;
                    break;
                }
                case FLOAT: {
                    float temp = *(int *) pipeObject.value + *(float *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case DOUBLE: {
                    double temp = *(int *) pipeObject.value + *(double *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case CHAR: {
                    if (!chrii(*(char *) a.value)) exit(NAN_VALUE);
                    int temp1 = *(int *) pipeObject.value;
                    int temp2 = (*(char *) a.value - '0');
                    int sum = temp1 + temp2;
                    pipeObject.value = &sum;
                    pipeObject.class = INT;
                    break;
                }
                default:
                    exit(NAN_CLASS);
            }
            break;
        }
        case FLOAT: {
            switch (a.class) {
                case INT: {
                    float temp = *(float *) pipeObject.value + *(int *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case FLOAT: {
                    float temp = *(float *) pipeObject.value + *(float *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case DOUBLE: {
                    double temp = *(float *) pipeObject.value + *(double *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case CHAR: {
                    float temp = *(float *) pipeObject.value + (*(char *) a.value - '0');
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case STRING: {
                    if (!strif(*(char **) a.value)) exit(NAN_VALUE);
                    float temp1 = *(float *) pipeObject.value;
                    float temp2 = strtod(*(char **) a.value, NULL);
                    float sum = temp1 + temp2;
                    pipeObject.value = &sum;
                    pipeObject.class = FLOAT;
                    break;
                }
                default:
                    exit(NAN_CLASS);
            }
            break;
        }
        case DOUBLE: {
            switch (a.class) {
                case INT: {
                    double temp = *(double *) pipeObject.value + *(int *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case FLOAT: {
                    double temp = *(double *) pipeObject.value + *(float *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case DOUBLE: {
                    double temp = *(double *) pipeObject.value + *(double *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case CHAR: {
                    double temp = *(double *) pipeObject.value + (*(char *) a.value - '0');
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case STRING:{
                    if (!strif(*(char **) a.value)) exit(NAN_VALUE);
                    double temp1 = *(double *) pipeObject.value;
                    double temp2 = strtod(*(char **) a.value, NULL);
                    double sum = temp1 + temp2;
                    pipeObject.value = &sum;
                    pipeObject.class = DOUBLE;
                    break;
                }
                default:
                    exit(NAN_CLASS);
            }
            break;
        }
        case CHAR: {
            switch (a.class) {
                case INT: {
                    if (!chrii(*(char *) pipeObject.value)) exit(NAN_VALUE);
                    int temp = (*(char *) pipeObject.value - '0') + *(int *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = INT;
                    break;
                }
                case FLOAT: {
                    if (!chrii(*(char *) pipeObject.value)) exit(NAN_VALUE);
                    float temp = (*(char *) pipeObject.value - '0') + *(float *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case DOUBLE: {
                    if (!chrii(*(char *) pipeObject.value)) exit(NAN_VALUE);
                    double temp = (*(char *) pipeObject.value - '0') + *(double *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case CHAR: {
                    if (!chrii(*(char *) pipeObject.value)
                        || !chrii(*(char *) a.value)) exit(NAN_VALUE);
                    uint8_t temp1 = *(char *) pipeObject.value - (uint8_t) '0';
                    uint8_t temp2 = *(char *) a.value - (uint8_t) '0';
                    uint8_t sum = temp1 + temp2;
                    if (sum > 9) {
                        char *temp3 = (char *) calloc(3, sizeof(char));
                        temp3[0] = sum / 10 + '0';
                        temp3[1] = sum % 10 + '0';
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else {
                        char temp3 = (char) (sum + (uint8_t) '0');
                        pipeObject.value = &temp3;
                        pipeObject.class = CHAR;
                    }
                } break;
                case STRING: {
                    if (!chrii(*(char *) pipeObject.value)) exit(NAN_VALUE);
                    if (strii(*(char **) a.value)) {
                        long long temp1 = *(char *) pipeObject.value - (uint8_t) '0';
                        long long temp2 = strtoll(*(char **) a.value, NULL, 10);
                        long long sum = temp1 + temp2;
                        if (sum > 9) {
                            char *temp3 = (char *) calloc(3, sizeof(char));
                            temp3[0] = sum / 10 + '0';
                            temp3[1] = sum % 10 + '0';
                            pipeObject.value = &temp3;
                            pipeObject.class = STRING;
                        } else {
                            char *temp3 = (char *) calloc(2, sizeof(char));
                            temp3[1] = sum + '0';
                            pipeObject.value = &temp3;
                            pipeObject.class = STRING;
                        }
                    } else if (strif(*(char **) a.value)){
                        double temp1 = *(char *) pipeObject.value - (uint8_t) '0';
                        double temp2 = strtod(*(char **) a.value, NULL);
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else exit(NAN_VALUE);
                }
                default:
                    exit(NAN_CLASS);
            }
            break;
        }
        case STRING: {
            switch (a.class) {
                case INT: {
                    if (strii(*(char **) pipeObject.value)) {
                        long long temp1 = strtoll(*(char **) pipeObject.value, NULL, 10);
                        long long temp2 = *(int *) a.value;
                        long long sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%lld", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else if (strif(*(char **) pipeObject.value)){
                        double temp1 = strtod(*(char **) pipeObject.value, NULL);
                        double temp2 = *(int *) a.value;
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else exit(NAN_VALUE);
                    break;
                }
                case FLOAT: {
                    if (strii(*(char **) pipeObject.value)) {
                        long long temp1 = strtoll((char *) pipeObject.value, NULL, 10);
                        double temp2 = *(float *) a.value;
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else if (strif(*(char **) pipeObject.value)){
                        double temp1 = strtod(*(char **) pipeObject.value, NULL);
                        double temp2 = *(float *) a.value;
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else exit(NAN_VALUE);
                    break;
                }
                case DOUBLE: {
                    if (strii(*(char **) pipeObject.value)) {
                        long long temp1 = strtoll(*(char **) pipeObject.value, NULL, 10);
                        double temp2 = *(double *) a.value;
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else if (strif(*(char **) pipeObject.value)){
                        double temp1 = strtod((char *) pipeObject.value, NULL);
                        double temp2 = *(double *) a.value;
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else exit(NAN_VALUE);
                    break;
                }
                case CHAR: {
                    if (!chrii(*(char *) a.value)) exit(NAN_VALUE);
                    if (strii(*(char **) pipeObject.value)) {
                        long long temp1 = strtoll(*(char **) pipeObject.value, NULL, 10);
                        long long temp2 = *(char *) a.value - (uint8_t) '0';
                        long long sum = temp1 + temp2;
                        if (sum > 9) {
                            char *temp3 = (char *) calloc(3, sizeof(char));
                            temp3[0] = sum / 10 + '0';
                            temp3[1] = sum % 10 + '0';
                            pipeObject.value = &temp3;
                            pipeObject.class = STRING;
                        } else {
                            char *temp3 = (char *) calloc(2, sizeof(char));
                            temp3[1] = sum + '0';
                            pipeObject.value = &temp3;
                            pipeObject.class = STRING;
                        }
                    } else if (strif(*(char **) pipeObject.value)){
                        double temp1 = strtod(*(char **) pipeObject.value, NULL);
                        double temp2 = *(char *) a.value - (uint8_t) '0';
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else exit(NAN_VALUE);
                    break;
                }
                case STRING:
                    if (strii(*(char **) pipeObject.value) && strii(*(char **) a.value)) {
                        long long temp1 = strtoll(*(char **) pipeObject.value, NULL, 10);
                        long long temp2 = strtoll(*(char **) a.value, NULL, 10);
                        long long sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%lld", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else if (strif(*(char **) pipeObject.value) && strif(*(char **) a.value)
                                   || strii(*(char **) pipeObject.value) && strif(*(char **) a.value)
                                   || strif(*(char **) pipeObject.value) && strii(*(char **) a.value)) {
                        double temp1 = strtod(*(char **) pipeObject.value, NULL);
                        double temp2 = strtod(*(char **) a.value, NULL);
                        double sum = temp1 + temp2;
                        char *temp3 = (char *) calloc(20, sizeof(char));
                        sprintf(temp3, "%f", sum);
                        pipeObject.value = &temp3;
                        pipeObject.class = STRING;
                    } else exit(NAN_VALUE);
                    break;
                default:
                    exit(NAN_CLASS);
            }
            break;
        }
        default:
            exit(NAN_CLASS);
    }
    nextObject;
}

NextObject sub(Object a) {
    nextObject;
}

NextObject mul(Object a) {
    nextObject;
}

NextObject divObject(Object a) {
    nextObject;
}

NextObject mod(Object a) {
    nextObject;
}

NextObject and(Object a) {
    nextObject;
}

NextObject or(Object a) {
    nextObject;
}

NextObject xor(Object a) {
    nextObject;
}

NextObject lsh(Object a) {
    nextObject;
}

NextObject rsh(Object a) {
    nextObject;
}

NextObject toChar() {
    nextObject;
}

NextObject toString() {
    nextObject;
}

NextObject toBool() {
    nextObject;
}

NextObject toOptional() {
    nextObject;
}

NextObject orElse(Object a) {
    nextObject;
}

NextObject isPresent() {
    nextObject;
}

NextObject ifPresent(void (*f)(Object)) {
    nextObject;
}

NextObject ifNotPresent(void (*f)()) {
    nextObject;
}

NextObject ifPresentOrElse(void (*f)(Object), void (*g)()) {
    nextObject;
}

NextObject map(Object (*f)(Object)) {
    nextObject;
}

NextObject flatMap(Object (*f)(Object)) {
    nextObject;
}

#include "error.h"
#include <object.h>
#include <stdbool.h>
#include <stdlib.h>

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
                    int temp = *(int *) pipeObject.value + *(char *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = INT;
                    break;
                }
                    exit(NAN_CLASS);
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
                    float temp = *(float *) pipeObject.value + *(char *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case STRING:
                    exit(NAN_CLASS);
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
                    double temp = *(double *) pipeObject.value + *(char*) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case STRING:
                    exit(NAN_CLASS);
                default:
                    exit(NAN_CLASS);
            }
            break;
        }
        case CHAR: {
            switch (a.class) {
                case INT: {
                    int temp = *(char *) pipeObject.value + *(int *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = INT;
                    break;
                }
                case FLOAT: {
                    float temp = *(char *) pipeObject.value + *(float *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case DOUBLE: {
                    double temp = *(char *) pipeObject.value + *(double *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case CHAR: {
                    uint8_t temp1 = *(char *) pipeObject.value - (uint8_t)'0';
                    uint8_t temp2 = *(char *) a.value - (uint8_t)'0';
                    if (temp1 < 0 || temp1 > 9 || temp2 < 0 || temp2 > 9) exit(NAN_VALUE);
                    uint8_t sum = temp1 + temp2;
                    if (sum > 9) {
                        char *temp3 = (char *) calloc(3, sizeof(char));
                        temp3[0] = sum / 10;
                        temp3[1] = sum % 10;
                        pipeObject.value = temp3;
                        pipeObject.class = STRING;
                    } else {
                        char temp3 = (char) (sum + (uint8_t)'0');
                        pipeObject.value = &temp3;
                        pipeObject.class = CHAR;
                    }
                }
                    break;
                case STRING:
                    exit(NAN_CLASS);
                default:
                    exit(NAN_CLASS);
            }
            break;
        }
        case STRING: {
            switch (a.class) {
                case INT: {
                    int temp = *(char *) pipeObject.value + *(int *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = INT;
                    break;
                }
                case FLOAT: {
                    float temp = *(char *) pipeObject.value + *(float *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = FLOAT;
                    break;
                }
                case DOUBLE: {
                    double temp = *(char *) pipeObject.value + *(double *) a.value;
                    pipeObject.value = &temp;
                    pipeObject.class = DOUBLE;
                    break;
                }
                case CHAR: {
                    uint8_t temp1 = *(char *) pipeObject.value - (uint8_t)'0';
                    uint8_t temp2 = *(char *) a.value - (uint8_t)'0';
                    if (temp1 < 0 || temp1 > 9 || temp2 < 0 || temp2 > 9) exit(NAN_VALUE);
                    uint8_t sum = temp1 + temp2;
                    if (sum > 9) {
                        char *temp3 = (char *) calloc(3, sizeof(char));
                        temp3[0] = sum / 10;
                        temp3[1] = sum % 10;
                        pipeObject.value = temp3;
                        pipeObject.class = STRING;
                    } else {
                        char temp3 = (char) (sum + (uint8_t)'0');
                        pipeObject.value = &temp3;
                        pipeObject.class = CHAR;
                    }
                }
                    break;
                case STRING:
                    exit(NAN_CLASS);
                default:
                    exit(NAN_CLASS);
            }
            break;
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

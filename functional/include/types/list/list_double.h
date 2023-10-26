#ifndef TYPES_LIST_DOUBLE_H_
#define TYPES_LIST_DOUBLE_H_

#define nextListDouble return FunctionsThatCanUseThePipeListDouble

#include <stdint.h>
#include <stdlib.h>

typedef struct ListDoubleStruct ListDoubleStruct;
typedef ListDoubleStruct *ListDouble;

struct ListDoubleStruct {
    double head;
    ListDouble tail;
    uint32_t size;
};

const uint64_t nilBits = 0x7ffadefeadedbeef;
const double nilDouble = __builtin_nan("0xadefeadedbeef");
ListDoubleStruct NilStruct = {.head = nilDouble, .tail = NULL, .size = 0};
ListDouble Nil = &NilStruct;

typedef struct NextDouble NextDouble;

/**
 * Struct containing functions that can be called on a pipeListDouble
 */
typedef struct NextListDouble NextListDouble;
typedef struct NextListDouble {
    ListDouble (*endPipe)();
    NextDouble (*get)(uint32_t);
    NextListDouble (*insert)(double);
    NextListDouble (*concat)(ListDouble);
} NextListDouble;

extern ListDouble pipeListDouble;
extern const NextListDouble FunctionsThatCanUseThePipeListDouble;

#endif//TYPES_LIST_DOUBLE_H_

#ifndef TYPES_FLOAT_H_
#define TYPES_FLOAT_H_

#include <stdbool.h>

#define nextFloat return FunctionsThatCanUseThePipeFloat

typedef struct {
    float value;
    bool isPresent;
} OptionalFloat;

typedef struct NextInt NextInt;

/**
 * Struct containing functions that can be called on a pipeFloat
 */
typedef struct NextFloat NextFloat;
typedef struct NextFloat {
    OptionalFloat (*endPipe)();
    float (*getValue)();
    NextFloat (*add)(OptionalFloat);
    NextFloat (*sub)(OptionalFloat);
    NextFloat (*mul)(OptionalFloat);
    NextFloat (*div)(OptionalFloat);
    NextFloat (*mod)(OptionalFloat);
    NextFloat (*pow)(OptionalFloat);
    NextFloat (*floor)();
    NextFloat (*ceil)();
    NextFloat (*round)();
    NextInt (*toInt)();
} NextFloat;

extern OptionalFloat pipeFloat;
extern const NextFloat FunctionsThatCanUseThePipeFloat;

#endif//TYPES_FLOAT_H_

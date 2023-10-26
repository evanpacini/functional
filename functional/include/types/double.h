#ifndef TYPES_DOUBLE_H_
#define TYPES_DOUBLE_H_

#include <stdbool.h>

#define nextDouble return FunctionsThatCanUseThePipeDouble

typedef struct {
    double value;
    bool isPresent;
} OptionalDouble;

typedef struct NextInt NextInt;

/**
 * Struct containing functions that can be called on a pipeDouble
 */
typedef struct NextDouble NextDouble;
typedef struct NextDouble {
    OptionalDouble (*endPipe)();
    double (*getValue)();
    NextDouble (*add)(OptionalDouble);
    NextDouble (*sub)(OptionalDouble);
    NextDouble (*mul)(OptionalDouble);
    NextDouble (*div)(OptionalDouble);
    NextDouble (*mod)(OptionalDouble);
    NextDouble (*pow)(OptionalDouble);
    NextDouble (*floor)();
    NextDouble (*ceil)();
    NextDouble (*round)();
    NextInt (*toInt)();
} NextDouble;

extern OptionalDouble pipeDouble;
extern const NextDouble FunctionsThatCanUseThePipeDouble;

#endif//TYPES_DOUBLE_H_

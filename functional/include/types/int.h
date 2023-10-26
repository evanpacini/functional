#ifndef TYPES_INT_H_
#define TYPES_INT_H_

#include <stdbool.h>

#define nextInt return FunctionsThatCanUseThePipeInt

typedef struct {
    int value;
    bool isPresent;
} OptionalInt;

typedef struct NextDouble NextDouble;
typedef struct NextFloat NextFloat;

/**
 * Struct containing functions that can be called on a pipeInt
 */
typedef struct NextInt NextInt;
typedef struct NextInt {
    OptionalInt (*endPipe)();
    int (*getValue)();
    NextInt (*add)(OptionalInt);
    NextInt (*sub)(OptionalInt);
    NextInt (*mul)(OptionalInt);
    NextInt (*div)(OptionalInt);
    NextInt (*mod)(OptionalInt);
    NextInt (*and)(OptionalInt);
    NextInt (* or)(OptionalInt);
    NextInt (*xor)(OptionalInt);
    NextInt (*lsh)(OptionalInt);
    NextInt (*rsh)(OptionalInt);
    NextFloat (*toFloat)();
    NextDouble (*toDouble)();
} NextInt;

extern OptionalInt pipeInt;
extern const NextInt FunctionsThatCanUseThePipeInt;

#endif//TYPES_INT_H_

#include <functional_int.h>
#include <stdlib.h>

OptionalInt pipeInt;

OptionalInt someInt(int value) {
    return (OptionalInt){value, true};
}

OptionalInt noneInt() {
    return (OptionalInt){0, false};
}

NextInt startPipeInt(OptionalInt a) {
    pipeInt = a;
    nextInt;
}

OptionalInt endPipeInt() {
    return pipeInt;
}

int getValueInt() {
    if (!pipeInt.isPresent) exit(INT_OPTIONAL_ABSENT);
    return pipeInt.value;
}

int getValueIntOr(int or) {
    return pipeInt.isPresent ? pipeInt.value : or ;
}

int getValueIntOrElse(int (*orElse)()) {
    return pipeInt.isPresent ? pipeInt.value : orElse();
}

NextInt addInt(OptionalInt a) {
    pipeInt.value += a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt subInt(OptionalInt a) {
    pipeInt.value -= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt mulInt(OptionalInt a) {
    pipeInt.value *= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt divInt(OptionalInt a) {
    pipeInt.value /= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt modInt(OptionalInt a) {
    pipeInt.value %= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt andInt(OptionalInt a) {
    pipeInt.value &= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt orInt(OptionalInt a) {
    pipeInt.value |= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt xorInt(OptionalInt a) {
    pipeInt.value ^= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt lshInt(OptionalInt a) {
    pipeInt.value <<= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextInt rshInt(OptionalInt a) {
    pipeInt.value >>= a.value;
    pipeInt.isPresent &= a.isPresent;
    nextInt;
}

NextFloat pipeIntToPipeFloat() {
    pipeFloat.value = (float) pipeInt.value;
    pipeFloat.isPresent = pipeInt.isPresent;
    nextFloat;
}
#include <functional_float.h>
#include <math.h>
#include <stdlib.h>

OptionalFloat pipeFloat;

OptionalFloat someFloat(float value) {
    return (OptionalFloat){value, true};
}

OptionalFloat noneFloat() {
    return (OptionalFloat){0, false};
}

NextFloat startPipeFloat(OptionalFloat a) {
    pipeFloat = a;
    nextFloat;
}

OptionalFloat endPipeFloat() {
    return pipeFloat;
}

float getValueFloat() {
    if (!pipeFloat.isPresent) exit(FLOAT_OPTIONAL_ABSENT);
    return pipeFloat.value;
}

NextFloat addFloat(OptionalFloat a) {
    pipeFloat.value += a.value;
    pipeFloat.isPresent &= a.isPresent;
    nextFloat;
}

NextFloat subFloat(OptionalFloat a) {
    pipeFloat.value -= a.value;
    pipeFloat.isPresent &= a.isPresent;
    nextFloat;
}

NextFloat mulFloat(OptionalFloat a) {
    pipeFloat.value *= a.value;
    pipeFloat.isPresent &= a.isPresent;
    nextFloat;
}

NextFloat divFloat(OptionalFloat a) {
    pipeFloat.value /= a.value;
    pipeFloat.isPresent &= a.isPresent;
    nextFloat;
}

NextFloat modFloat(OptionalFloat a) {
    pipeFloat.value = fmodf(pipeFloat.value, a.value);
    pipeFloat.isPresent &= a.isPresent;
    nextFloat;
}

NextFloat powFloat(OptionalFloat a) {
    pipeFloat.value = powf(pipeFloat.value, a.value);
    pipeFloat.isPresent &= a.isPresent;
    nextFloat;
}

NextFloat floorFloat() {
    pipeFloat.value = floorf(pipeFloat.value);
    nextFloat;
}

NextFloat ceilFloat() {
    pipeFloat.value = ceilf(pipeFloat.value);
    nextFloat;
}

NextFloat roundFloat() {
    pipeFloat.value = roundf(pipeFloat.value);
    nextFloat;
}

NextInt pipeFloatToPipeInt() {
    pipeInt.value = (int) pipeFloat.value;
    pipeInt.isPresent = pipeFloat.isPresent;
    nextInt;
}
#include <functional_double.h>
#include <math.h>
#include <stdlib.h>

OptionalDouble pipeDouble;

OptionalDouble someDouble(double value) {
    return (OptionalDouble){value, true};
}

OptionalDouble noneDouble() {
    return (OptionalDouble){0, false};
}

NextDouble startPipeDouble(OptionalDouble a) {
    pipeDouble = a;
    nextDouble;
}

OptionalDouble endPipeDouble() {
    return pipeDouble;
}

double getValueDouble() {
    if (!pipeDouble.isPresent) exit(DOUBLE_OPTIONAL_ABSENT);
    return pipeDouble.value;
}

NextDouble addDouble(OptionalDouble a) {
    pipeDouble.value += a.value;
    pipeDouble.isPresent &= a.isPresent;
    nextDouble;
}

NextDouble subDouble(OptionalDouble a) {
    pipeDouble.value -= a.value;
    pipeDouble.isPresent &= a.isPresent;
    nextDouble;
}

NextDouble mulDouble(OptionalDouble a) {
    pipeDouble.value *= a.value;
    pipeDouble.isPresent &= a.isPresent;
    nextDouble;
}

NextDouble divDouble(OptionalDouble a) {
    pipeDouble.value /= a.value;
    pipeDouble.isPresent &= a.isPresent;
    nextDouble;
}

NextDouble modDouble(OptionalDouble a) {
    pipeDouble.value = fmod(pipeDouble.value, a.value);
    pipeDouble.isPresent &= a.isPresent;
    nextDouble;
}

NextDouble powDouble(OptionalDouble a) {
    pipeDouble.value = pow(pipeDouble.value, a.value);
    pipeDouble.isPresent &= a.isPresent;
    nextDouble;
}

NextDouble floorDouble() {
    pipeDouble.value = floor(pipeDouble.value);
    nextDouble;
}

NextDouble ceilDouble() {
    pipeDouble.value = ceil(pipeDouble.value);
    nextDouble;
}

NextDouble roundDouble() {
    pipeDouble.value = round(pipeDouble.value);
    nextDouble;
}

NextInt pipeDoubleToPipeInt() {
    pipeInt.value = (int) pipeDouble.value;
    pipeInt.isPresent = pipeDouble.isPresent;
    nextInt;
}
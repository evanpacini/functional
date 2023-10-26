#ifndef FUNC_DOUBLE_H
#define FUNC_DOUBLE_H

#include <error.h>
#include <types/double.h>
#include <types/int.h>

#define $d(x) startPipeDouble(x)

/**
 * Wraps a double in an OptionalDouble
 * @param value the double value
 * @return      the OptionalDouble
 */
extern OptionalDouble someDouble(double value);

/**
 * Returns an empty OptionalDouble
 * @return the OptionalDouble
 */
extern OptionalDouble noneDouble();

/**
 * Sets up the OptionalDouble pipeDouble
 * @param a OptionalDouble to start the pipeDouble with
 * @return functions that can be called on pipeDouble
 */
extern NextDouble startPipeDouble(OptionalDouble a);

/**
 * Gets the OptionalDouble of the current OptionalDouble pipeDouble
 * @param _pipe current OptionalDouble pipeDouble
 * @return OptionalDouble
 */
extern OptionalDouble endPipeDouble();

/**
 * Gets the double value of the current OptionalDouble pipeDouble
 * @param _pipe current OptionalDouble pipeDouble
 * @return double value
 */
extern double getValueDouble();

/**
 * Adds an OptionalDouble to the OptionalDouble pipeDouble
 * @param _pipe current OptionalDouble pipeDouble
 * @param a OptionalDouble to add
 * @return functions that can be called on pipeDouble
 */
extern NextDouble addDouble(OptionalDouble a);

/**
 * Subtracts an OptionalDouble from the OptionalDouble pipeDouble
 * @param _pipe current OptionalDouble pipeDouble
 * @param a OptionalDouble to subtract
 * @return functions that can be called on pipeDouble
 */
extern NextDouble subDouble(OptionalDouble a);

/**
 * Multiplies an OptionalDouble with the OptionalDouble pipeDouble
 * @param _pipe current OptionalDouble pipeDouble
 * @param a OptionalDouble to multiply with
 * @return functions that can be called on pipeDouble
 */
extern NextDouble mulDouble(OptionalDouble a);

/**
 * Divides an OptionalDouble from the OptionalDouble pipeDouble
 * @param _pipe current OptionalDouble pipeDouble
 * @param a OptionalDouble to divide with
 * @return functions that can be called on pipeDouble
 */
extern NextDouble divDouble(OptionalDouble a);

/**
 * Modulos an OptionalDouble from the OptionalDouble pipeDouble
 * @param _pipe current OptionalDouble pipeDouble
 * @param a OptionalDouble to modulo with
 * @return functions that can be called on pipeDouble
 */
extern NextDouble modDouble(OptionalDouble a);

/**
 * Raises the current OptionalDouble pipeDouble (base) to the power of the given OptionalDouble (exponent)
 * @param _pipe current OptionalDouble pipeDouble (base)
 * @param a OptionalDouble (exponent)
 * @return functions that can be called on pipeDouble
 */
extern NextDouble powDouble(OptionalDouble a);

/**
 * Floors the current pipeDouble
 * @param _pipe current pipeDouble
 * @return functions that can be called on pipeDouble
 */
extern NextDouble floorDouble();

/**
 * Ceils the current pipeDouble
 * @param _pipe current pipeDouble
 * @return functions that can be called on pipeDouble
 */
extern NextDouble ceilDouble();

/**
 * Rounds the current pipeDouble
 * @param _pipe current pipeDouble
 * @return functions that can be called on pipeDouble
 */
extern NextDouble roundDouble();

/**
 * Sends the current pipeDouble to the pipeInt using floor
 * @param _pipe current pipeDouble
 * @return functions that can be called on pipeInt
 */
extern NextInt pipeDoubleToPipeInt();

const NextDouble FunctionsThatCanUseThePipeDouble = {
    .endPipe = &endPipeDouble,
    .getValue = &getValueDouble,
    .add = &addDouble,
    .sub = &subDouble,
    .mul = &mulDouble,
    .div = &divDouble,
    .mod = &modDouble,
    .pow = &powDouble,
    .floor = &floorDouble,
    .ceil = &ceilDouble,
    .round = &roundDouble,
    .toInt = &pipeDoubleToPipeInt,
};

#endif// FUNC_DOUBLE_H
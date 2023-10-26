#ifndef FUNC_FLOAT_H
#define FUNC_FLOAT_H

#include <error.h>
#include <types/float.h>
#include <types/int.h>

#define $f(x) startPipeFloat(x)

/**
 * Wraps a float in an OptionalFloat
 * @param value the float value
 * @return      the OptionalFloat
 */
extern OptionalFloat someFloat(float value);

/**
 * Returns an empty OptionalFloat
 * @return the OptionalFloat
 */
extern OptionalFloat noneFloat();

/**
 * Sets up the OptionalFloat pipeFloat
 * @param a OptionalFloat to start the pipeFloat with
 * @return functions that can be called on pipeFloat
 */
extern NextFloat startPipeFloat(OptionalFloat a);

/**
 * Gets the OptionalFloat of the current OptionalFloat pipeFloat
 * @param _pipe current OptionalFloat pipeFloat
 * @return OptionalFloat
 */
extern OptionalFloat endPipeFloat();

/**
 * Gets the float value of the current OptionalFloat pipeFloat
 * @param _pipe current OptionalFloat pipeFloat
 * @return float value
 */
extern float getValueFloat();

/**
 * Adds an OptionalFloat to the OptionalFloat pipeFloat
 * @param _pipe current OptionalFloat pipeFloat
 * @param a OptionalFloat to add
 * @return functions that can be called on pipeFloat
 */
extern NextFloat addFloat(OptionalFloat a);

/**
 * Subtracts an OptionalFloat from the OptionalFloat pipeFloat
 * @param _pipe current OptionalFloat pipeFloat
 * @param a OptionalFloat to subtract
 * @return functions that can be called on pipeFloat
 */
extern NextFloat subFloat(OptionalFloat a);

/**
 * Multiplies an OptionalFloat with the OptionalFloat pipeFloat
 * @param _pipe current OptionalFloat pipeFloat
 * @param a OptionalFloat to multiply with
 * @return functions that can be called on pipeFloat
 */
extern NextFloat mulFloat(OptionalFloat a);

/**
 * Divides an OptionalFloat from the OptionalFloat pipeFloat
 * @param _pipe current OptionalFloat pipeFloat
 * @param a OptionalFloat to divide with
 * @return functions that can be called on pipeFloat
 */
extern NextFloat divFloat(OptionalFloat a);

/**
 * Modulos an OptionalFloat from the OptionalFloat pipeFloat
 * @param _pipe current OptionalFloat pipeFloat
 * @param a OptionalFloat to modulo with
 * @return functions that can be called on pipeFloat
 */
extern NextFloat modFloat(OptionalFloat a);

/**
 * Raises the current OptionalFloat pipeFloat (base) to the power of the given OptionalFloat (exponent)
 * @param _pipe current OptionalFloat pipeFloat (base)
 * @param a OptionalFloat (exponent)
 * @return functions that can be called on pipeFloat
 */
extern NextFloat powFloat(OptionalFloat a);

/**
 * Floors the current pipeFloat
 * @param _pipe current pipeFloat
 * @return functions that can be called on pipeFloat
 */
extern NextFloat floorFloat();

/**
 * Ceils the current pipeFloat
 * @param _pipe current pipeFloat
 * @return functions that can be called on pipeFloat
 */
extern NextFloat ceilFloat();

/**
 * Rounds the current pipeFloat
 * @param _pipe current pipeFloat
 * @return functions that can be called on pipeFloat
 */
extern NextFloat roundFloat();

/**
 * Sends the current pipeFloat to the pipeInt using floor
 * @param _pipe current pipeFloat
 * @return functions that can be called on pipeInt
 */
extern NextInt pipeFloatToPipeInt();

const NextFloat FunctionsThatCanUseThePipeFloat = {
    .endPipe = &endPipeFloat,
    .getValue = &getValueFloat,
    .add = &addFloat,
    .sub = &subFloat,
    .mul = &mulFloat,
    .div = &divFloat,
    .mod = &modFloat,
    .pow = &powFloat,
    .floor = &floorFloat,
    .ceil = &ceilFloat,
    .round = &roundFloat,
    .toInt = &pipeFloatToPipeInt,
};

#endif// FUNC_FLOAT_H
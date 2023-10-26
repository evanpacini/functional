#ifndef FUNC_INT_H
#define FUNC_INT_H

#include <error.h>
#include <types/float.h>
#include <types/int.h>

#define $i(x) startPipeInt(x)

/**
 * Wraps an integer in an OptionalInt
 * @param value the integer value
 * @return      the OptionalInt
 */
extern OptionalInt someInt(int value);

/**
 * Returns an empty OptionalInt
 * @return the OptionalInt
 */
extern OptionalInt noneInt();

/**
 * Sets up the OptionalInt pipeFloat
 * @param a OptionalInt to start the pipeFloat with
 * @return functions that can be called on pipeInt
 */
extern NextInt startPipeInt(OptionalInt a);

/**
 * Gets the OptionalInt of the current OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @return OptionalInt
 */
extern OptionalInt endPipeInt();

/**
 * Gets the int value of the current OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @return int value
 */
extern int getValueInt();

/**
 * Adds an OptionalInt to the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to add
 * @return functions that can be called on pipeInt
 */
extern NextInt addInt(OptionalInt a);

/**
 * Subtracts an OptionalInt from the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to subtract
 * @return functions that can be called on pipeInt
 */
extern NextInt subInt(OptionalInt a);

/**
 * Multiplies an OptionalInt with the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to multiply with
 * @return functions that can be called on pipeInt
 */
extern NextInt mulInt(OptionalInt a);

/**
 * Divides an OptionalInt from the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to divide with
 * @return functions that can be called on pipeInt
 */
extern NextInt divInt(OptionalInt a);

/**
 * Modulos an OptionalInt from the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to modulo with
 * @return functions that can be called on pipeInt
 */
extern NextInt modInt(OptionalInt a);

/**
 * Bitwise ANDs an OptionalInt with the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to AND with
 * @return functions that can be called on pipeInt
 */
extern NextInt andInt(OptionalInt a);

/**
 * Bitwise ORs an OptionalInt with the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to OR with
 * @return functions that can be called on pipeInt
 */
extern NextInt orInt(OptionalInt a);

/**
 * Bitwise XORs an OptionalInt with the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to XOR with
 * @return functions that can be called on pipeInt
 */
extern NextInt xorInt(OptionalInt a);

/**
 * Bitwise left shifts an OptionalInt with the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to left shift with
 * @return functions that can be called on pipeInt
 */
extern NextInt lshInt(OptionalInt a);

/**
 * Bitwise right shifts an OptionalInt with the OptionalInt pipeFloat
 * @param _pipe current OptionalInt pipeFloat
 * @param a OptionalInt to right shift with
 * @return functions that can be called on pipeInt
 */
extern NextInt rshInt(OptionalInt a);

/**
 * Sends the current pipeInt to the pipeFloat
 * @param _pipe current pipeInt
 * @return functions that can be called on pipeFloat
 */
extern NextFloat pipeIntToPipeFloat();

const NextInt FunctionsThatCanUseThePipeInt = {
    .endPipe = &endPipeInt,
    .getValue = &getValueInt,
    .add = &addInt,
    .sub = &subInt,
    .mul = &mulInt,
    .div = &divInt,
    .mod = &modInt,
    .and = &andInt,
    .or = &orInt,
    .xor = &xorInt,
    .lsh = &lshInt,
    .rsh = &rshInt,
    .toFloat = &pipeIntToPipeFloat,
};

#endif// FUNC_INT_H
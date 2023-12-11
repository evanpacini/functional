#ifndef FUNCTIONAL_OBJECT_H
#define FUNCTIONAL_OBJECT_H

#include <types/object.h>

#define $o startPipe

/**
 * Creates an object
 *
 * @param class Class of the object
 * @param value Value of the object
 * @return Object with the given class and value
 */
 extern Object newObject (Class class, void* value);

/**
 * Sets up the Object pipe
 * @param a Object to start the pipe with
 * @return functions that can be called on pipe
 */
extern NextObject startPipe(Object a);

/**
 * Gets the Object of the current Object pipe
 * @param _pipe current Object pipe
 * @return Object
 */
extern Object endPipe();

/**
 * Gets the Object of the current Object pipe
 * @param _pipe current Object pipe
 * @return Object
 */
extern void* getValue();

/**
 * Gets the class of the current Object pipe
 * @param _pipe current Object pipe
 * @return Class
 */
extern Class getClass();

/**
 * Gets the float value of the current Object pipe
 * @param _pipe current Object pipe
 * @return float value
 */
extern NextObject toFloat();

/**
 * Gets the double value of the current Object pipe
 * @param _pipe current Object pipe
 * @return double value
 */
extern NextObject toDouble();

/**
 * Gets the int value of the current Object pipe
 * @param _pipe current Object pipe
 * @return int value
 */
extern NextObject toInt();

/**
 * Adds an Object to the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to add
 * @return functions that can be called on pipe
 */
extern NextObject add(Object a);

/**
 * Subtracts an Object from the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to subtract
 * @return functions that can be called on pipe
 */
extern NextObject sub(Object a);

/**
 * Multiplies an Object with the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to multiply with
 * @return functions that can be called on pipe
 */
extern NextObject mul(Object a);

/**
 * Divides an Object from the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to divide with
 * @return functions that can be called on pipe
 */
extern NextObject divObject(Object a);

/**
 * Modulos an Object from the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to modulo with
 * @return functions that can be called on pipe
 */
extern NextObject mod(Object a);

/**
 * Bitwise ands an Object with the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to bitwise and with
 * @return functions that can be called on pipe
 */
extern NextObject and(Object a);

/**
 * Bitwise ors an Object with the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to bitwise or with
 * @return functions that can be called on pipe
 */
extern NextObject or(Object a);

/**
 * Bitwise xors an Object with the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to bitwise xor with
 * @return functions that can be called on pipe
 */
extern NextObject xor(Object a);

/**
 * Bitwise left shifts an Object with the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to bitwise left shift with
 * @return functions that can be called on pipe
 */
extern NextObject lsh(Object a);

/**
 * Bitwise right shifts an Object with the Object pipe
 * @param _pipe current Object pipe
 * @param a Object to bitwise right shift with
 * @return functions that can be called on pipe
 */
extern NextObject rsh(Object a);

/**
 * Gets the char value of the current Object pipe
 * @param _pipe current Object pipe
 * @return char value
 */
extern NextObject toChar();

/**
 * Gets the string value of the current Object pipe
 * @param _pipe current Object pipe
 * @return string value
 */
extern NextObject toString();

/**
 * Gets the bool value of the current Object pipe
 * @param _pipe current Object pipe
 * @return bool value
 */
extern NextObject toBool();

/**
 * Gets the Optional value of the current Object pipe
 * @param _pipe current Object pipe
 * @return Optional value
 */
extern NextObject toOptional();

/**
 * Gets the value of the Optional value of the current Object pipe
 * @param _pipe current Object pipe
 * @param a Object to return if the Optional value is not present
 * @return value of the Optional value
 */
extern NextObject orElse(Object a);

/**
 * Checks if the Optional value of the current Object pipe is present
 * @param _pipe current Object pipe
 * @return true if the Optional value is present, false otherwise
 */
extern NextObject isPresent();

/**
 * Executes a function on the value of the Optional value of the current Object pipe if it is present
 * @param _pipe current Object pipe
 * @param f Function to execute
 * @return functions that can be called on pipe
 */
extern NextObject ifPresent(void (*f)(Object));

/**
 * Executes a function if the Optional value of the current Object pipe is not present
 * @param _pipe current Object pipe
 * @param f Function to execute
 * @return functions that can be called on pipe
 */
extern NextObject ifNotPresent(void (*f)());

/**
 * Executes a function on the value of the Optional value of the current Object pipe if it is present, otherwise executes another function
 * @param _pipe current Object pipe
 * @param f Function to execute if the Optional value is present
 * @param g Function to execute if the Optional value is not present
 * @return functions that can be called on pipe
 */
extern NextObject ifPresentOrElse(void (*f)(Object), void (*g)());

/**
 * Executes a function on the value of the Optional value of the current Object pipe if it is present and returns the Optional value of the function
 * @param _pipe current Object pipe
 * @param f Function to execute
 * @return functions that can be called on pipe
 */
extern NextObject map(Object (*f)(Object));

/**
 * Executes a function on the value of the Optional value of the current Object pipe if it is present and returns the Optional value of the function
 * @param _pipe current Object pipe
 * @param f Function to execute
 * @return functions that can be called on pipe
 */
extern NextObject flatMap(Object (*f)(Object));

/**
 * Struct containing functions that can be called on a pipe
 */
const NextObject FunctionsThatCanUseThePipeObject = {
    .endPipe = &endPipe,
    .getValue = &getValue,
    .getClass = &getClass,
    .toFloat = &toFloat,
    .toDouble = &toDouble,
    .toInt = &toInt,
    .add = &add,
    .sub = &sub,
    .mul = &mul,
    .div = &divObject,
    .mod = &mod,
    .and = &and,
    .or = &or,
    .xor = &xor,
    .lsh = &lsh,
    .rsh = &rsh,
    .toChar = &toChar,
    .toString = &toString,
    .toBool = &toBool,
    .toOptional = &toOptional,
    .orElse = &orElse,
    .isPresent = &isPresent,
    .ifPresent = &ifPresent,
    .ifNotPresent = &ifNotPresent,
    .ifPresentOrElse = &ifPresentOrElse,
    .map = &map,
    .flatMap = &flatMap
};

#endif//FUNCTIONAL_OBJECT_H

#ifndef FUNCTIONAL_TYPES_OBJECT_H
#define FUNCTIONAL_TYPES_OBJECT_H

#define nextObject return FunctionsThatCanUseThePipeObject

typedef enum {
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING,
    BOOL,
    OPTIONAL,
    VOID
} Class;

typedef struct {
    void* value;
    Class class;
} Object;

typedef struct NextObject NextObject;

typedef struct NextObject {
    Object (*endPipe)();
    void* (*getValue)();
    Class (*getClass)();
    NextObject (*toFloat)();
    NextObject (*toDouble)();
    NextObject (*toInt)();
    NextObject (*add)(Object);
    NextObject (*sub)(Object);
    NextObject (*mul)(Object);
    NextObject (*div)(Object);
    NextObject (*mod)(Object);
    NextObject (*and)(Object);
    NextObject (* or)(Object);
    NextObject (*xor)(Object);
    NextObject (*lsh)(Object);
    NextObject (*rsh)(Object);
    NextObject (*toChar)();
    NextObject (*toString)();
    NextObject (*toBool)();
    NextObject (*toOptional)();
    NextObject (*orElse)(Object);
    NextObject (*isPresent)();
    NextObject (*ifPresent)(void (*f)(Object));
    NextObject (*ifNotPresent)(void (*f)());
    NextObject (*ifPresentOrElse)(void (*f)(Object), void (*g)());
    NextObject (*map)(Object (*f)(Object));
    NextObject (*flatMap)(Object (*f)(Object));
} NextObject;

#endif//FUNCTIONAL_TYPES_OBJECT_H
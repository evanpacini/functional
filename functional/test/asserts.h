#ifndef ASSERTS_H
#define ASSERTS_H

#include <stdbool.h>

extern void assert(bool condition, const char *message);

extern void assertStringEqual(const char *a, const char *b, const char *message);

extern void assertFloatEqual(const float a, const float b, const char *message);

extern void assertDoubleEqual(const double a, const double b, const char *message);

extern void assertIntEqual(const int a, const int b, const char *message);

extern void assertBoolEqual(const bool a, const bool b, const char *message);

extern void assertOptionalFloatEqual(const OptionalFloat a, const OptionalFloat b, const char *message);

extern void assertOptionalIntEqual(const OptionalInt a, const OptionalInt b, const char *message);

extern void assertOptionalDoubleEqual(const OptionalDouble a, const OptionalDouble b, const char *message);

extern void assertListDoubleEqual(const ListDouble a, const ListDouble b, const char *message);

//extern void assertListIntEqual(const ListFloat a, const ListFloat b, const char *message);
//
//extern void assertListStringEqual(const ListString a, const ListString b, const char *message);
//
//extern void assertListBoolEqual(const ListBool a, const ListBool b, const char *message);

#endif//ASSERTS_H

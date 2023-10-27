#include "types/list/list_double.h"

ListDoubleStruct NilStruct = {.head = __builtin_bit_cast(double, nilBits), .tail = nullptr, .size = 0};
extern "C" ListDouble NilDouble = &NilStruct;

#include <stdarg.h>
#include <types/list/list_double.h>

uint32_t helper_ListDoubleX(va_list args, ListDouble aboveList) {
    double arg = va_arg(args, double);
    if (*((uint64_t *) &arg) == nilBits) return 0;
    ListDouble newList = (ListDouble) malloc(sizeof(ListDouble));
    if (newList == NULL) exit(LIST_DOUBLE_MALLOC_ERROR);
    newList->head = arg;
    newList->tail = NilDouble;
    aboveList->tail = newList;
    uint32_t size = 1 + helper_ListDoubleX(args, newList);
    newList->size = size;
    return size;
}

ListDouble helper_lastReference(ListDouble ld) {
    return ld->tail->headBits == nilBits ? ld : helper_lastReference(ld->tail);
}

void helper_updateSize(ListDouble ld, uint32_t addedSize) {
    ld->size += addedSize;
    if (ld->size > addedSize + 1)
        helper_updateSize(ld->tail, addedSize);
}

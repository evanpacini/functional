#include <stdarg.h>
#include <types/list/list_double.h>

ListDouble helper_newListDouble(double head, ListDouble tail) {
    ListDouble list = (ListDouble) malloc(sizeof(ListDouble));
    if (list == NULL) exit(LIST_DOUBLE_MALLOC_ERROR);
    list->head = head;
    list->tail = tail;
    list->size = tail->size + 1;
    return list;
}

ListDouble helper_makeDeepCopyListDouble(ListDouble ld) {
    if (ld->headBits == nilBits) return NilDouble;
    return helper_newListDouble(ld->head, helper_makeDeepCopyListDouble(ld->tail));
}

uint32_t helper_ListDoubleX(va_list args, ListDouble aboveList) {
    double arg = va_arg(args, double);
    if (*((uint64_t *) &arg) == nilBits) return 0;
    ListDouble newList = helper_newListDouble(arg, NilDouble);
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

ListDouble helper_mapToDoubleListDouble(ListDouble ld, double (*f)(double)) {
    if (ld->headBits == nilBits) return NilDouble;
    return helper_newListDouble(f(ld->head), helper_mapToDoubleListDouble(ld->tail, f));
}

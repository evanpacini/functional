#include <error.h>
#include <list/functional_list_double.h>
#include <stdio.h>
#include <string.h>

#include "helpers/helper_list_double.c"

ListDouble pipeListDouble;

ListDouble newNilDouble() {
    ListDouble list = (ListDouble) malloc(sizeof(ListDouble));
    if (list == NULL) exit(LIST_DOUBLE_MALLOC_ERROR);
    list->head = NilDoubleX->head;
    list->tail = NilDoubleX->tail;
    list->size = 0;
    return list;
}

ListDouble ListDoubleX(double head, ...) {
    va_list args;
    va_start(args, head);
    ListDouble list = helper_newListDouble(head, NilDouble);
    list->size = 1 + helper_ListDoubleX(args, list);
    return list;
}

NextListDouble startPipeListDouble(ListDouble a) {
    pipeListDouble = helper_makeDeepCopyListDouble(a);
    nextListDouble;
}

ListDouble endPipeListDouble() {
    return pipeListDouble;
}

const char *toStringListDouble(ListDouble list) {
    ListDouble head = list;
    char *str = malloc(list->size * 18 + 13);
    if (str == NULL) exit(LIST_DOUBLE_MALLOC_ERROR);
    strcpy(str, "ListDouble(");
    while (head->headBits != nilBits) {
        char *str2 = malloc(19);
        if (str2 == NULL) exit(LIST_DOUBLE_MALLOC_ERROR);
        sprintf(str2, "%.10e, ", head->head);
        strcat(str, str2);
        free(str2);
        head = head->tail;
    }
    strcat(str, ")");
    return str;
}

ListDouble helper_getValueListDouble(uint32_t i, ListDouble ld) {
    if (i >= ld->size) return NilDouble;
    if (i == 0) return ld;
    return helper_getValueListDouble(--i, ld->tail);
}

NextDouble getValueListDouble(uint32_t i) {
    ListDouble ld = helper_getValueListDouble(i, pipeListDouble);
    if (ld->headBits == nilBits) {
        pipeDouble.isPresent = false;
        nextDouble;
    }
    pipeDouble.value = ld->head;
    pipeDouble.isPresent = true;
    nextDouble;
}

NextListDouble insertListDouble(double head) {
    pipeListDouble = helper_newListDouble(head, pipeListDouble);
    nextListDouble;
}

NextListDouble concatListDouble(ListDouble a) {
    helper_lastReference(pipeListDouble)->tail = a;
    helper_updateSize(pipeListDouble, a->size);
    nextListDouble;
}

NextListDouble mapToDoubleListDouble(double (*f)(double)) {
    pipeListDouble = helper_mapToDoubleListDouble(pipeListDouble, f);
    nextListDouble;
}

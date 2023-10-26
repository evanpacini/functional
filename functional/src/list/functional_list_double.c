#include <list/functional_list_double.h>
#include <stdio.h>
#include <string.h>

#include "helpers/helper_list_double.c"

ListDouble pipeListDouble;

ListDouble ListDoubleX(double head, ...) {
    va_list args;
    va_start(args, head);
    ListDouble list = (ListDouble) malloc(sizeof(ListDouble));
    list->head = head;
    list->tail = NilDouble;
    list->size = 1 + helper_ListDoubleX(args, list);
    return list;
}

NextListDouble startPipeListDouble(ListDouble a) {
    pipeListDouble = a;
    nextListDouble;
}

ListDouble endPipeListDouble() {
    return pipeListDouble;
}

const char *toStringListDouble(ListDouble list) {
    ListDouble head = list;
    char *str = malloc(list->size * 18 + 13);
    strcpy(str, "ListDouble(");
    while (head != NilDouble) {
        char *str2 = malloc(19);
        sprintf(str2, "%.10e, ", head->head);
        strcat(str, str2);
        free(str2);
        head = head->tail;
    }
    strcat(str, ")");
    return str;
}

NextDouble getValueListDouble(uint32_t i) {
    if (i >= pipeListDouble->size) {
        pipeDouble.isPresent = false;
        nextDouble;
    }
    if (i == 0) {
        pipeDouble.value = pipeListDouble->head;
        pipeDouble.isPresent = true;
        nextDouble;
    }
    pipeListDouble = pipeListDouble->tail;
    return getValueListDouble(--i);
}

NextListDouble insertListDouble(double head) {
    ListDouble newList = malloc(sizeof(ListDouble));
    newList->head = head;
    newList->tail = pipeListDouble;
    pipeListDouble = newList;
    nextListDouble;
}

NextListDouble concatListDouble(ListDouble a) {
    helper_lastReference(pipeListDouble)->tail = a;
    helper_updateSize(pipeListDouble, a->size);
    nextListDouble;
}
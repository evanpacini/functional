#ifndef LIST_DOUBLE_FUNC_H_
#define LIST_DOUBLE_FUNC_H_

#include <stdarg.h>
#include <types/double.h>
#include <types/list/list_double.h>

#define NilDouble newNilDouble()
#define ListDouble(...) ListDoubleX(__VA_ARGS__, NilDoubleX->head)
#define $ld(x) startPipeListDouble(x)

/**
 *
 * @param head
 * @param tail
 * @return
 */
extern ListDouble newNilDouble();

/**
 *
 * @param head
 * @param ...
 * @return
 */
extern ListDouble ListDoubleX(double head, ...);

/**
 *
 * @param a
 * @return
 */
extern NextListDouble startPipeListDouble(ListDouble a);

/**
 *
 * @return
 */
extern ListDouble endPipeListDouble();

/**
 *
 * @param list
 * @return
 */
extern const char *toStringListDouble(ListDouble list);

/**
 *
 * @param i
 * @return
 */
extern NextDouble getValueListDouble(uint32_t i);

/**
 *
 * @param head
 * @return
 */
extern NextListDouble insertListDouble(double head);

/**
 *
 * @param a
 * @return
 */
extern NextListDouble concatListDouble(ListDouble a);

/**
 *
 * @param f
 * @return
 */
extern NextListDouble mapToDoubleListDouble(double (*f)(double));

const NextListDouble FunctionsThatCanUseThePipeListDouble = {
    .endPipe = &endPipeListDouble,
    .get = &getValueListDouble,
    .insert = &insertListDouble,
    .concat = &concatListDouble,
    .mapToDouble = &mapToDoubleListDouble,
};

#endif//LIST_DOUBLE_FUNC_H_

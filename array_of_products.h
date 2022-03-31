#ifndef __ARRAYS_OF_PRODUCTS_H__
#define __ARRAYS_OF_PRODUCTS_H__

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int8_t vsBool;

void printResult(int64_t *outputList, int64_t listSize);

vsBool setProducList(int64_t *numbersList,
                     int64_t numbersListSize,
                     int64_t *outputList,
                     int64_t outputListSize);

#endif /* #ifndef __ARRAYS_OF_PRODUCTS_H__ */

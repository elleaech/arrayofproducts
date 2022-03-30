#ifndef __ARRAYS_OF_PRODUCTS_H__
#define __ARRAYS_OF_PRODUCTS_H__

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int8_t vsBool;

vsBool setProducList(int32_t *numbersList,
                     int32_t numbersListSize,
                     int32_t *outputList,
                     int32_t outputListSize);

#endif /* #ifndef __ARRAYS_OF_PRODUCTS_H__ */
